#include<bits/stdc++.h>
using namespace std;
int T,n,a[5][100005],maxn=-1,maxi,sum,ans,s[5];
int flag1=0;
vector<int>b[5];
void dfs(int cur,int cnt,int tarb,int need) {
	if(cnt==need) {
//		for(int i=1;i<=3;i++) {
//				for(int j=0;j<b[i].size();j++) {
//					sum+=b[i][j];
//				}
//			}
//		}
		sum=s[1]+s[2]+s[3];
//		cout<<s[1]<<" "<<s[2]<<" "<<s[3]<<"\n";
		ans=max(ans,sum);
		return;
	}
//	else if(cur>n) return;
	for(int j=cur+1;j<=n;j++) {
		maxn=-1;
		for(int i=1;i<=3;i++) {
			if(a[i][j]>maxn&&i!=tarb) {
				maxn=a[i][j];
				maxi=i;
			}
		}
		s[tarb]-=a[tarb][j];
		s[maxi]+=a[maxi][j];
		b[tarb][j]=0;
		dfs(j,cnt+1,tarb,need);
		s[tarb]+=a[tarb][j];
		s[maxi]-=a[maxi][j];
		b[tarb].push_back(j);
		dfs(j,cnt,tarb,need);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		//氟 
		ans=-1;sum=0;flag1=0;
		b[1].clear();
		b[2].clear();
		b[3].clear();
		s[1]=s[2]=s[3]=0;
		for(int j=1;j<=n;j++) {
			maxn=-1;
			//铀 
			for(int i=1;i<=3;i++) {
				cin>>a[i][j];
				if(a[i][j]>maxn) {
					maxn=a[i][j];
					maxi=i;
				}
			}
			b[maxi].push_back(j);
			s[maxi]+=a[maxi][j];
		}
		//碳 
		for(int i=1;i<=3;i++) {
			if(b[i].size()>(n/2)) {
				flag1=i;
				break;
			}
		}
		if(flag1==0) {
			for(int j=1;j<=n;j++) {
				sum+=max(a[1][j],max(a[2][j],a[3][j]));
			}
			cout<<sum<<"\n";
		}
		else {
			//钾 
			dfs(1,1,flag1,n); 
			dfs(1,0,flag1,n);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
//password:人5杰4地4灵5%
/*
What a awful T is it,to waste me 1.5h!
Can anyone tell me,b vector铥的有用吗? 
我决定死磕这一题了!
好吧，我失败了Shift+6 
	 --------
	/		 \
   | ()  ()  |
   | ||  ||  |
   |   ^     |
   \        /
    -------
OI!See You Again!
服了，这OI学了跟学了一样 
keywords:
feropen
club.cpp
road.cpp
replace.cpp
employ.cpp
clud
clab
raod
repalce
repacle
empty
emplay
enploy
"r",stdout
"w",stdin
ccf
luogu
kkksc03
Ren5Jie4Di4Ling5%
AK
IOI
CSP
CSP-S
CSP-J
NOIp
NOI
APIO
ICPC
WC
freopen("D:\GD-S03177\club\club.in","r",stdin);
freopen("D:\GD-S03177\club\club.out","w",stdout);

Can anyone find my 4 chemical secrets in the 4 .cpp?
*/
