#include<bits/stdc++.h>
using namespace std;
int m,n;
struct stu{
	bool k;
	int gra;
}a[10001];
cmp(stu x,stu y){
	return x.gra>y.gra;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].gra;
	}
	a[1].k=1;
	sort(a+1,a+n*m+1,cmp);
	int bi=0;
	int anx=1,any=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].k==1){
			bi=i;
		}
	}
	int cnt=0;
	for(int j=1;j<=m;j++){	
		if(j%2){
			for(int i=1;i<=n;i++){
				cnt++;
				if(cnt==bi){
					cout<<j<<" "<<i;
					break;
				}
			}
		}else if(j%2==0){
			for(int i=n;i>0;i--){
				cnt++;
				if(cnt==bi){
					cout<<j<<" "<<i;
					break;
					}
				}
			}
		}
	return 0;
}
