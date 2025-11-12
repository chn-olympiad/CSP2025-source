#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],z,p,m1=1;
bool shu=true;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=n*m;
	for(int i=1;i<=p;i++) cin>>a[i];
	z=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=p;i++){
		if(a[i]==z){
			z=i; break;
		}
	}
	int o=p;
	for(int i=1;i<=n;i++){
		if(shu){
			for(int j=1;j<=m;j++){
				if(o==z){
					cout<<i<<" "<<j; return 0;
				}
				o--;
			}
			shu=0;
		}else{
			for(int j=m;j>=1;j--){
				if(o==z){
					cout<<i<<" "<<j; return 0;
				}
				o--;
			}
			shu=1;
		}
	}
	return 0;
}
