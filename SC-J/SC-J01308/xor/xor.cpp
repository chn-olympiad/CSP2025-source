#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N],s[N],vis[N]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	s[1]=a[1];
	for(long long i=2;i<=n;i++)
	    s[i]=s[i-1]^a[i];
	for(long long i=1;i<=n;i++){//枚举区间 
		for(long long j=i;j<=n;j++){
			long long num=abs(s[j]-s[i-1]);
			bool check=true;
			for(int l=i;l<=j;l++)
			    if(vis[l]==1){
			    	check=false;
			    	break;
				}
			if(k==num&&check==true){
				for(long long q=i;q<=j;q++)
				    vis[q]=1;
				ans++;
			}
		}
	}
	cout<<ans;
} 