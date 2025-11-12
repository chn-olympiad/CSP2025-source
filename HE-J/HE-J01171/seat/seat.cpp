#include <bits/stdc++.h>
using namespace std;
int n,m,v,l=1;
struct asd{
	int id,p;
}a[300];
bool cmp(asd a,asd b){
	return a.p>b.p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin >>n>>m;
	v=n*m;
	for(int i=1;i<=v;i++){
		cin >>a[i].p;
		a[i].id=i;
	}
	sort(a+1,a+1+v,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[l].id==1){
					cout <<i<<" "<<j;
					return 0;
				}
				l++;
			}
		}else{
			for(int j=1;j<=n;j++){
				if(a[l].id==1){
					cout <<i<<" "<<j;
					return 0;
				}
				l++;
			}
		}
	}
	return 0;
}
