//这道题真是把做局展现得淋漓尽致 
//100+48+0+8=156=AFO
//神，不惧死亡！ 
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,cnt,cntt,c[510],day_who[510],ans;
bool day_difficulty[510];
int tai_cai_le_si_le[510];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
void dfs(int k){
	if(k>n){
		memset(tai_cai_le_si_le,0,sizeof tai_cai_le_si_le);
		int sum=0;
		for(int i=1;i<=n;i++){
			if(tai_cai_le_si_le[day_who[i]]<c[day_who[i]]&&day_difficulty[i]){
				sum++;
			}
			else{
				for(int j=i+1;j<=n;j++){
					tai_cai_le_si_le[day_who[j]]++;
				}
			}
		}
		if(sum>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!day_who[i]){
			day_who[i]=k;
			dfs(k+1);
			day_who[i]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	char ch=getchar();
	while(ch<'0'||ch>'1')ch=getchar();
	while(ch>='0'&&ch<='1'){
		if(ch=='1')cntt++;
		day_difficulty[++cnt]=ch-'0';
		ch=getchar();
	}
	if(ch<=m){
		putchar('0');
		return 0;
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	dfs(1);
	printf("%d",ans%mod);
	return 0;
}
/*10 5
1101111011
6 0 4 2 1 2 5 4 3 3*/

