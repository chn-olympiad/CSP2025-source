#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],ans,pos[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	b[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
		if(a[i]==k){
			ans++;
			pos[++cnt]=i;
		}
	}
	if(cnt!=0) pos[0]=1;
	for(int i=1;i<=cnt;i++){
		for(int j=pos[i-1];j<pos[i]-1;j++){
			for(int k=j+1;k<=pos[i]-1;k++){
				int x=b[k]^b[j-1];
				if(x==k) ans++;
			}
		}
	}
	for(int i=pos[cnt]+1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int x=b[j]^b[i-1];
			if(x==k) ans++;
		}
	}
	cout<<ans;
	return 0;
} 
