#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cn[509],nm;
	char cm[509];  //must 0
	scanf("%d%d",&n,&m);  nm=n;
	for(int i=0;i<n;i++)  cin>>cm[i];
	for(int i=0;i<n;i++)  scanf("%d",&cn[i]);
	for(int i=0;i<nm;i++){
		if(cn[i]==0)  n--;
	}long long ans=1;
	for(int i=1;i<=n;i++)  ans=ans*i%998244353;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
