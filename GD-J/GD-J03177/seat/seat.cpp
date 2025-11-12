#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	bool f=0;
	int cnt=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(f==0){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
			f=1;
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
			f=0;
		}
	}
	return 0;
}
