#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],n,z,k,s[N],f[N],p[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==k){
		f[1]=1;
		p[1]=1;
	}else{
		f[1]=0;
		p[1]=0;		
	}
	for(int i=2;i<=n;i++){
		bool f1=0,f2=0;
		int ans=a[i];
		if(ans==k){
			f1=1,f2=1;
		}
		if(!f2){	
			for(int j=i-1;j>=p[i-1]+1;j--){
				ans^=a[j];
				if(ans==k){
					f1=1;
					break;
				}
			}
		}
		if(f1)p[i]=i,f[i]=f[i-1]+1;
		else f[i]=f[i-1],p[i]=p[i-1];
	}
	cout<<f[n];
}		
