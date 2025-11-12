#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001],b[100001],ed[100001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]^b[i-1];
	}
	for(int i=1;i<=n;i++){
		ed[i]=2e8;
		for(int j=i;j<=n;j++){
			int sb=b[j]^b[i-1];
			if(sb==k){
				ed[i]=j;
				break;
			}
		}
	}
	int cnt=2e8,ans=0;
	for(int i=1;i<=n;i++){
		cnt=min(cnt,ed[i]);
		if(i==cnt){
			cnt=2e8;
			ans++;
			continue;
		}
	}
	cout<<ans<<endl;
	return 0;
}
