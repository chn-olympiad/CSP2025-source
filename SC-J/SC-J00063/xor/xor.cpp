#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200012];
int num[255];
int vis[200012];
bool flag1=1,flag2=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[a[i]]++;
		if(a[i]!=1) flag1=0;
		if(a[i]!=1&&a[i]!=0) flag2=0;
	}
	if(flag1&&k!=1){
		cout<<n/2;
		return 0;
	}
	int ans=num[k];
	if(k==0){
		for(int i=1;i<=n;i++){
			if(i>1&&a[i]!=0&&a[i]==a[i-1]&&!vis[i]&&!vis[i-1]){
				vis[i]=1;
				vis[i-1]=1;
				ans++;	
			}
		}
	}
	cout<<ans;
	return 0;
}