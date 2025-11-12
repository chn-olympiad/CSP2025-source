#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],ans;
bool c[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0&&n<=2) cout<<n;
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}for(int i=1;i<=n;i++){
			for(int j=i-1;j<=n;j++) b[j]=0;
			for(int j=i;j<=n;j++){
				b[j]=(b[j-1]^a[j]);
				if(b[j]==k){
					int l=-1,r=-1;
					for(int k=i;k<=j;k++){
						if(l!=-1&&!c[k]){
							r=k-1;
							break;
						}if(c[k]&&l==-1) l=k;
					}bool flag=0;
					if(l!=-1&&r-l<j-i) continue;
					if(l!=-1&&r-l>j-i){
						for(int k=l;k<=r;k++) c[k]=0;
					}
					ans++;
					for(int k=i;k<=j;k++) c[k]=1;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
