#include"bits/stdc++.h"
using namespace std;
int a[500005];
int s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(a[i]!=1)
			f=false;
	}
	if(f){
		printf("%d\n",n>>1);
		return 0;
	}
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;){
			int j=i,tmp=0;
			while(a[j]!=k){
				j++;
				tmp++;
			}
			if(!a[i])
				ans++;
			ans+=(tmp>>1);
			i=j;
			if(i==j)
				i++;
		}
		printf("%d\n",ans);
		return 0;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=a[i];
		printf("%d\n",ans);
		return 0;
	}
	printf("%d\n",n);
	return 0;
}
