#include<bits/stdc++.h>
using namespace std;
const int INF=20005;
int ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int sp1[INF],dsp[INF];//替换词中b的位置 
	int p1[INF],dp[INF];//问题中b的位置 
	int len[INF],slen[INF];//问题字符串的长度  和  替换词的长度 
	int n,q;
	cin>>n>>q;
	char c;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt=0;
		while(c!=' '){
			cnt++;
			c=getchar();
			if(c=='b')sp1[i]=cnt;
		}
		slen[i]=cnt; 
		cnt=0;
		while(c!='\n'){
			cnt++;
			c=getchar();
			if(c=='b')dsp[i]=sp1[i]-cnt;
		}
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		while(c!=' '){
			cnt++;
			c=getchar();
			if(c=='b')p1[i]=cnt;
		}
		len[i]=cnt;
		cnt=0;
		while(c!='\n'){
			cnt++;
			c=getchar();
			if(c=='b')dp[i]=p1[i]-cnt;
		}
	}
	int a,b;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			a=min(slen[j]-sp1[j]+1,slen[j]-sp1[j]+dsp[j]+1);
			b=min(sp1[j],sp1[j]-dsp[j]);
			if(len[i]>dp[i]){
				if(min(a,b)<=sp1[j]&&sp1[j]<=max(a,b)){
					if(min(a,b)<=sp1[j]-dsp[j]&&sp1[j]-dsp[j]<=max(a,b)){
						if(dsp[j]==dp[i])  ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
