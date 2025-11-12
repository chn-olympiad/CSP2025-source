#include<bits/stdc++.h>
#define fre(ss,i,j,k) for(int ss=i;ss<=j;ss+=k)
#define rep(ss,i,j,k) for(int ss=i;ss>=j;ss-=k)
using namespace std;
const int N=2e5,M=5e6;
const long long mod1=998244353,mod2=1000000007;
int n,q,ans[N+5];
long long P1=131,PC1[M+5],P2=13331,PC2[M+5];
struct SSS{string s1,s2;int len,qlen,st,en;long long Hqa1,Hqa2,Hqb1,Hqb2,H1,H2;}s[N+5];
struct TTT{string t1,t2;int len,qlen,st,en;long long Hqa1,Hqa2,Hqb1,Hqb2;vector<long long>H1,H2;}t[N+5];
bool check(int ids,int idt){
	if(s[ids].qlen!=t[idt].qlen||s[ids].Hqa1!=t[idt].Hqa1||s[ids].Hqa2!=t[idt].Hqa2||s[ids].Hqb1!=t[idt].Hqb1||s[ids].Hqb2!=t[idt].Hqb2)return 0;
	int l=t[idt].st-s[ids].st,r=t[idt].en+(s[ids].len-1-s[ids].en);
	if(l<0||r>=t[idt].len)return 0;
	if(l==0)return s[ids].H1==t[idt].H1[r]&&s[ids].H2==t[idt].H2[r];
	else return s[ids].H1==(t[idt].H1[r]-t[idt].H1[l-1]*PC1[r-l+1]%mod1+mod1)%mod1
				&&s[ids].H2==(t[idt].H2[r]-t[idt].H2[l-1]*PC2[r-l+1]%mod2+mod2)%mod2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	PC1[0]=PC2[0]=1;fre(i,1,M,1)PC1[i]=PC1[i-1]*P1%mod1,PC2[i]=PC2[i-1]*P2%mod2;
	cin>>n>>q;
	fre(i,1,n,1){
		cin>>s[i].s1>>s[i].s2;s[i].len=s[i].s1.length();
		fre(j,0,s[i].len-1,1)if(s[i].s1[j]!=s[i].s2[j]){s[i].st=j;break;}
		rep(j,s[i].len-1,0,1)if(s[i].s1[j]!=s[i].s2[j]){s[i].en=j;break;}
		s[i].qlen=s[i].en-s[i].st+1;
		fre(j,s[i].st,s[i].en,1){
			s[i].Hqa1=(s[i].Hqa1*P1%mod1+s[i].s1[j])%mod1;
			s[i].Hqa2=(s[i].Hqa2*P2%mod2+s[i].s1[j])%mod2;
			s[i].Hqb1=(s[i].Hqb1*P1%mod1+s[i].s2[j])%mod1;
			s[i].Hqb2=(s[i].Hqb2*P2%mod2+s[i].s2[j])%mod2;
		}
		fre(j,0,s[i].len-1,1){
			s[i].H1=(s[i].H1*P1%mod1+s[i].s1[j])%mod1;
			s[i].H2=(s[i].H2*P2%mod2+s[i].s1[j])%mod2;
		}
	}
	fre(i,1,q,1){
		cin>>t[i].t1>>t[i].t2;t[i].len=t[i].t1.length();
		fre(j,0,t[i].len-1,1)if(t[i].t1[j]!=t[i].t2[j]){t[i].st=j;break;}
		rep(j,t[i].len-1,0,1)if(t[i].t1[j]!=t[i].t2[j]){t[i].en=j;break;}
		t[i].qlen=t[i].en-t[i].st+1;
		fre(j,t[i].st,t[i].en,1){
			t[i].Hqa1=(t[i].Hqa1*P1%mod1+t[i].t1[j])%mod1;
			t[i].Hqa2=(t[i].Hqa2*P2%mod2+t[i].t1[j])%mod2;
			t[i].Hqb1=(t[i].Hqb1*P1%mod1+t[i].t2[j])%mod1;
			t[i].Hqb2=(t[i].Hqb2*P2%mod2+t[i].t2[j])%mod2;
		}
		t[i].H1.push_back(t[i].t1[0]%mod1);
		t[i].H2.push_back(t[i].t1[0]%mod2);
		fre(j,1,t[i].len-1,1){
			t[i].H1.push_back((t[i].H1[j-1]*P1%mod1+t[i].t1[j])%mod1);
			t[i].H2.push_back((t[i].H2[j-1]*P2%mod2+t[i].t1[j])%mod2);
		}
	}
	fre(i,1,n,1)fre(j,1,q,1)ans[j]+=check(i,j);
	fre(i,1,q,1)cout<<ans[i]<<"\n";
	return 0;
}