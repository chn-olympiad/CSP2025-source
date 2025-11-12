/*
ִ���˼����־��
��������AKһ�Σ�
��Դ֮Ŀ������ 
*/ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
const int maxn=505;
const int mod=998244353;
char s[maxn];
int jc[maxn];
int cnt[maxn];
int f[2][maxn][maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=(ll)jc[i-1]*i%mod;
	scanf("%s",s+1);
	int cnt1=0; 
	int lim=0;
	for(int i=1,c;i<=n;i++){	
		scanf("%d",&c);
		c--;
		if(c>=0) cnt[c]++;
		if(s[i]=='1') cnt1++;
		else lim++;
	}
	if(cnt1<m){
		puts("0");
		return 0;
	}
	for(int i=n;i>=0;i--) cnt[i]+=cnt[i+1];
	for(int i=0;i<=cnt1-m;i++) f[(n+1)&1][i][0]=1;
	for(int i=n;i>=1;i--){
		if(s[i]=='0'){
			lim--;
			for(int j=0;j<=cnt1-m;j++)
				for(int k=0;k<=n;k++) f[i&1][j][k]=f[(i+1)&1][j][k];
			continue;
		}	
		int o=(i&1),o2=(o^1);
		for(int j=0;j<=cnt1-m;j++) for(int k=0;k<=n;k++) f[o][j][k]=0;
		for(int j=0;j<=cnt1-m;j++){
			for(int k=0;k<=n;k++){
				if(!f[o2][j][k]) continue;
				if(lim+j<=n && cnt[lim+j]-k>0)
					f[o][j][k+1]=(f[o][j][k+1]+(ll)f[o2][j][k]*(cnt[lim+j]-k)%mod)%mod;//������ 
				//���� �ն�
				if(j && lim+j-1<=n && cnt[lim+j-1]-k>0)
					f[o][j-1][k+1]=(f[o][j-1][k+1]-(ll)f[o2][j][k]*(cnt[lim+j-1]-k)%mod+mod)%mod;
				//���� ���ն� 
				if(j)
					f[o][j-1][k]=(f[o][j-1][k]+f[o2][j][k]%mod)%mod; 
			}
		}
	}
	int ans=0;
	for(int k=0;k<=n;k++){
		ans=(ans+(ll)f[1][0][k]*jc[n-k]%mod)%mod;
	}
	printf("%d",ans);
	return 0;
} 
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

5 2
11111
0 2 2 2 1

102

�о� AK �� 
*/
