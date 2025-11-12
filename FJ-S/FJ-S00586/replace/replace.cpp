#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pss pair<string,string>
#define pcc pair<char,char>
const int N=2e5+5,L=5e6+5,p=131;
int n,q,ll,rr,cnt;
string s[N][3],t[2];
ull hs[N][3],sum[L][3],fac[L];
ull get_all(string str){
	ull ans=0;
	for(int i=0;i<str.size();i++)
		ans=ans*p+(int)(str[i]-'a'+1);
	return ans;
}
void get_sum(string str,int op){
	sum[0][op]=str[0]-'a'+1;
	for(int i=1;i<str.size();i++)
		sum[i][op]=sum[i-1][op]*p+(str[0]-'a'+1);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		hs[i][1]=get_all(s[i][1]);
		hs[i][2]=get_all(s[i][2]);
	}fac[0]=1;
	for(int i=1;i<=L-5;i++)
		fac[i]=fac[i-1]*p;
	while(q--){
		string x,y;int tot=0;
		cin>>x>>y;
		if(x.size()!=y.size()){
			puts("0");continue;
		}
		memset(sum,0,sizeof(sum));
		get_sum(x,1);get_sum(y,2);
		ll=0;rr=x.size()-1;
		while(ll<x.size()&&x[ll]==y[ll])ll++;
		while(rr>=0&&x[rr]==y[rr])rr--;
		int len=rr-ll+1;
		for(int i=1;i<=n;i++){
			if(s[i][1].size()<len||s[i][1].size()>x.size())continue;
			for(int j=rr-s[i][1].size()+1;j<=ll;j++){
				int jj=j+s[i][1].size()-1;
				if(jj>x.size())break;
				if(sum[jj][1]-sum[j-1][1]==hs[i][1]*fac[j-1]&&sum[jj][2]-sum[j-1][2]==hs[i][2]*fac[j-1])tot++;
			}
		}
		printf("%d\n",tot);
	}
	return 0;
}
