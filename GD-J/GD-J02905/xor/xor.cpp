#include<bits/stdc++.h>
using namespace std;

int n,k,a[500010],ans,x,y,b[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			a[i]=-1;
			ans++;
		}
	}
	for(int l=2;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			if(a[i]==-1){
				for(int j=1;j<=y;j++) b[j]=0;
				x=0,y=0;
				continue;
			}
			Flag:;
			if(y==0){
				x=a[i];
				b[++y]=i;
			}else if(y!=l-1){
				x=x^a[i];
				b[++y]=i;
			}else if(y==l-1){
				x=x^a[i];
				b[++y]=i;
				if(x==k){
					ans++;
					for(int j=1;j<=y;j++){
						a[b[j]]=-1;
						b[j]=0;
					}
					y=0,x=0;
				}else{
					i=b[2];
					for(int j=1;j<=y;j++) b[j]=0;
					y=0,x=0;
					if(i==n) break;
					goto Flag;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
