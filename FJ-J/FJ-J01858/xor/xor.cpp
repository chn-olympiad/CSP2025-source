#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],c[105],cnt,dp[1000005],maxx,kk=1,shang,ma,yu;
struct dfg{
	int l,r;
}we[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		ma=max(ma,a[i]);
		if(a[i]==1){
			yu++;
		}
		b[i]=b[i-1]^a[i];
		
	}
	if(k<=1&& ma<=1&&n>=5005){
		cout<<yu<<endl;
		return 0;
	}
	for(int l = 1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((b[r]^b[l-1])==k){
				cnt++;
				we[cnt].l=l;
				we[cnt].r=r;
				break;
			}
		}
	}
	/*
	for(int l = 1;l<=n;l++){
		
		if(cnt==0){
			for(int r=l;r<=n;r++){
				if((b[r]^b[l-1])==k){
					cnt++;
					we[cnt].l=l;
					we[cnt].r=r;
					kk=r;
					shang=l;
					break;
				}
			}
		}
		else if(l>we[cnt].r){
			for(int r=l;r<=n;r++){
				if((b[r]^b[l-1])==k){
					cnt++;
					we[cnt].l=l;
					we[cnt].r=r;
					kk=r;
					shang=l;
					break;
				}
			}
		}
		else{
			for(int r=kk+1;r<=n;r++){
				if((b[r]^b[kk])==(b[l-1]^b[shang-1])){
					cnt++;
					we[cnt].l=l;
					we[cnt].r=r;
					kk=r;
					shang=l;
					break;
				}
			}
		}
		
	}*/
	for(int i = 1;i<=cnt;i++){
		int dl=we[i].l;
		int dr=we[i].r;
		dp[dr]=max(dp[dr],dp[dl-1]+1);
		for(int j = dr+1;j<=n;j++){
			dp[j]=max(dp[j],dp[dr]);
		}
	}
	for(int i = 1;i<=n;i++){
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx;
}
