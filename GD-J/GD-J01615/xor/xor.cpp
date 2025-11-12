#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500009];
int s[500009];
int pos[2000009];//1048575
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int r=0,ans=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		int t=pos[s[i]^k];
		pos[s[i]]=i;
		if(s[t]^s[i]==k){
			if(r<t+1){
				r=i;
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}

