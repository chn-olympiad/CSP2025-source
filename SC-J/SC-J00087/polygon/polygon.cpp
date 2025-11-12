#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,mod=998244353,sum,a[N],b[1010][1010],m=3;
int www(int num,int sp,int lon,int mb){
	if(sp==1) return a[num];
	lon+=a[num];
	int c;
	for(int i=1;i<num;i++){
	if(sp!=m){c=lon+www(num-i,sp-1,lon,mb);
	//cout<<num<<" "<<num-i<<" "<<c<<endl;
	}
	else lon+www(num-i,sp-1,lon,mb);
	if(c>mb) {//cout<<"L"<<c<<endl;
	sum=(sum+1)%mod;}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int j=m;j<n;j++){
	for(int i=0;i<n-1;i++){
		int p=a[n-i],q=2*p;
		if(n-i>=j){
			//cout<<p<<endl;
			www(n-i,j,0,q);
			//cout<<endl;
			}
		}
	}
	int z=0,p=a[n],q=2*p;
	for(int i=1;i<=n;i++){
		z+=a[i];
	}
	if(z>q)sum=(sum+1)%mod;
	cout<<sum%mod;
}