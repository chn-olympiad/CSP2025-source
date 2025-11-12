#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans=0,s=0;
bool f=0,b[500005];
void bout(long long a,long long c){
	for(long long i=a;i<=c;i++){
		b[i]=1;
		s++;
	}
}	
void solve(long long x,long long y){
	long long tot=0;
	bool g=0;
	for(long long i=x;i<=y+x;i++){
		tot=tot^a[i];
		if(b[i]==1){
			g=1;
			break;
		}
	}
	//cout<<tot<<endl;
	if(tot==k&&g==0)f=1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long h=0;h<=n-1;h++){
		for(long long i=1;i<=n-h;i++){
			if(s==n){
				cout<<ans;
				return 0;
			}
			solve(i,h);
			if(f==1){
				ans++;
				f=0;
				bout(i,i+h);
			}
		}
	}
	cout<<ans;
	return 0;
}
