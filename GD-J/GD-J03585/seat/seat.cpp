#include<bits/stdc++.h>
using namespace std;
int n,m;
struct student{
	int pos,dis;
};
student a[105];
bool cmp(student x,student y){
	return x.dis>y.dis;
}
int main(){
	ifstream r("seat.in");
	ofstream w("seat.out");
	r>>n>>m;
	for(int i=1;i<=n*m;i++){
		r>>a[i].dis;
		a[i].pos=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[(i-1)*m+j].pos==1){
					w<<i<<' '<<j;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[i*m-j+1].pos==1){
					w<<i<<' '<<j;
				}
			}
		}
	}
	r.close();
	w.close();
	return 0;
}
