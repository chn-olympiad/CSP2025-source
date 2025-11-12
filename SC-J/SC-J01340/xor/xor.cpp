#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=2e6+5;
int n,k;
int a[N],ps[N];
void solve1(){
	int lst=0,ans=0;
	for(int r=1;r<=n;r++){
		for(int l=lst+1;l<=r;l++){
			if((ps[r]^ps[l-1])==k){
				ans++;
				lst=r;
				break;
			}
		}
	}
	printf("%d",ans);
}
int cnt[M],wst[M];
void solve2(){
	int lst=0,ans=0;
	cnt[0]=1;
	for(int r=1;r<=n;r++){
		int tgt=k^ps[r];
		if(cnt[tgt]-wst[tgt]){
			ans++;
			for(int i=lst;i<r;i++)wst[ps[i]]++;
			lst=r;
		}
		cnt[ps[r]]++;
	}
	printf("%d",ans);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ps[i]=ps[i-1]^a[i];
	}
	if(n<=1000)solve1();
	else solve2();
	return 0;
}