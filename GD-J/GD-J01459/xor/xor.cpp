#include<bits/stdc++.h>
using namespace std;
int n,k,ans,t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n+7]={0},numi[n+7],numj[n+7];
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int num=a[i];
		if(num==k){
			ans++;	
			numi[++t]=i;
			numj[t]=i;
		}
		for(int j=i+1;j<=n;j++){
			num^=a[j];
			if(num==k){
				ans++;
				numi[++t]=i;
				numj[t]=j;
				break;
			}
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=i-1;j>=1;j--){
			if(numi[j]>=numi[i]&&numi[j]<=numj[i]) ans--;
			else if(numi[i]>=numi[j]&&numi[i]<=numj[j]) ans--;
		}
	}
	return cout<<ans,0;
}

