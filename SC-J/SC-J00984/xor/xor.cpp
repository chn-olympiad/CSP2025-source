#include<bits/stdc++.h>
using namespace std;
int n,k,a[500006],c[500006];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			c[i]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]==i){
			continue;
		}
		else{
			int t=a[i];
		    for(int j=i+1;j<=n;j++){
			    t^=a[j];
			    if(t==k){
				    c[j]=max(c[j],i); 
					break;
		        }
		    }
		}
	}
	int ans=0,zt=0;
	for(int i=1;i<=n;i++){
		if(c[i]!=0&&zt<c[i]){
			zt=i;
			ans++;
		}
	}
	cout<<ans;
}