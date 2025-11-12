#include<bits/stdc++.h>
using namespace std;
long long n,k,x,a[500005],a0,a1,ans,s[500005];
int b[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	b[++cnt]=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==0)a0++;
		if(x==1)a1++;
		if(x==k){
			ans++;
			a[i]=-1,b[++cnt]=i;
		}else{
			a[i]=x,s[i]=s[i-1]^x;
		}
	}
	if(a1==n){
		cout<<n/2;
	}else if(a0==n){
		cout<<n;
	}else if((a0+a1)==n){
		if(k){
			cout<<ans;
		}else{
			cout<<a1/2+ans;
		}
	}else{
		b[++cnt]=n+1;
		for(int i=2;i<=cnt;i++){
			int l=b[i-1]+1,r=b[i]-1,N=(r-l+1)*(r-l);
			vector<bool> v(N);
			int id=l,pre=l-1;
			while(id<=r){
				int w=s[id]^s[pre];
				if(w==k){
					ans++,pre=id;
				}else if(v[w^k]){
					ans++,v[w^k]=0,pre=id;
				}
				else v[w]=1;
				id++;
			}
		}
		cout<<ans;
	}
	return 0;
}
