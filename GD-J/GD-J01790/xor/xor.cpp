#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500001]={0};
long long vis[500001]={0};
bool check(int x,int y){
	for(int i=x;i<=y;i++){
		if(vis[i]==1)return false;
	}
	return true;
}
long long por(long long x,long long y){
	long long ans=0;
	if(x==y){
		return a[x];
	}
	else{
		for(long long i=x;i<y;i++){
			string b="",c="";
			long long p=a[i];
			while(p>0){
				b+=((p%2)+'0');
				p/=2;
			}
			long long q=a[i+1];
			while(q>0){
				c+=((q%2)+'0');
				q/=2;
			}
			long long len=max(b.length(),c.length());
			b+='0',c+='0';
			for(long long j=0;j<len;j++){
				if(b[j]=='0')b+='0';
				if(c[j]=='0')c+='0';
			}
			long long sum=0;
			for(long long j=len-1;j>=0;j--){
				if(b[j]!=c[j]){
					if(j==0){
						sum+=1;
					}
					else{
						sum+=(10*j);
					}
				}
			}
			a[i+1]=sum;
		}
		return a[y];
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(por(i,j)==k&&check(i,j)){
				for(int u=i;u<=j;u++){
					vis[u]=1;
				}
				ans++;
			}
		}
	}
	cout<<ans;
}
