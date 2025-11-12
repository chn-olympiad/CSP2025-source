#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500010],b[500010],ans,x,u=1,flag;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(b,0x3f,sizeof(b));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		x=0;
		for(int j=i;j<=n;j++){
			x^=a[j];
			if(x==k){
				b[i]=j;
				break;
			}
		}
	}
	while(u<=n){
		if(b[u]<500010){
			ans++;flag=0;
			for(int i=u+1;i<=b[u];i++){
				if(b[i]<b[u]){
					u=i-1;ans--;flag=1;
					break;
				}
			}
			if(!flag)u=b[u];
		}
		u++;
	}
	cout<<ans;
}
