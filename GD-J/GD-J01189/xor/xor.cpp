#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005],l[1005],h[1005],ans,f1;
bool f[1005][1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])	f1=1;
	}
	if(!f1)	cout<<n;
	else if(n<=1000){
		for(int i=1;i<=n;i++){
			int aa=0;
			for(int j=i;j<=n;j++){
				aa^=a[j];
				if(aa==k)	f[i][j]=1;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i;j<=n;j++)
//				cout<<f[i][j];
//			cout<<endl;
//		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)	if(f[i][j]){h[i]++;l[j]++;}
		for(int i=1;i<=n;i++){
			if(h[i]!=0){
				int minn=l[1],mini=1;
				for(int j=1;j<=n;j++){
					if(f[i][j]&&l[j]<minn){
						minn=l[j];
						mini=j;
					}
				}
				for(int j=1;j<=n;j++){
					if(f[j][mini]==1)	h[j]--;
					f[j][mini]=0;
				}
				l[mini]=0x7f7f7f7f;	
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}

