#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1[200100],s2[200100],s3[200100],s4[200100];int ans[200100];
long long qp[5000010],qp2[5000010];
struct Node{
	long long c1,c2,c3,c4;
	int idx;
}hx[500100];
const long long mod=998244353,mod2=1e9+7;
bool cmp(Node a,Node b){
	if(a.c1!=b.c1)return a.c1<b.c1;
	else if(a.c2!=b.c2) return a.c2<b.c2;
	else if(a.c3!=b.c3)return a.c3<b.c3;
	else if(a.c4!=b.c4) return a.c4<b.c4;
	else return a.idx<b.idx;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i <= n;i++){
		string s,ss;
		cin>>s>>ss;
		s1[i]=s,s2[i]=ss;
	}
	for(int i=1;i <= m;i++){
		string s,ss;
		cin>>s>>ss;
		s3[i]=s,s4[i]=ss;
	}
	if(n<=100){
		for(int i=1;i <= m;i++){
			if(s3[i].size()!=s4[i].size()){ puts("0");continue;}
			for(int j=1;j <= n;j++){
				for(int k=0;k < (int)s3[i].size()&&k+s1[j].size()-1<s3[i].size();k++){
					string g=s3[i].substr(k,s1[j].size()),gg=s4[i].substr(k,s2[j].size());
					string h,hh;
					for(int l=0;l < k;l++) h+=s3[i][l];
					for(int l=k+s1[j].size();l < s3[i].size();l++) hh+=s3[i][l];
					if(g==s1[j]&&gg==s2[j]&&h+gg+hh==s4[i]){
						ans[i]++;
					}
				}
			}
			cout<<ans[i]<<"\n";
		}
	}else{
		qp[0]=qp2[0]=1;
		for(int i=1;i <= 5000000;i++){
			qp[i]=qp[i-1]*10;
			qp[i]%=mod;
			qp2[i]=qp2[i-1]*10;
			qp2[i]%=mod2;
		}
		for(int i=1;i <= n;i++){
			string s,ss;
			s=s1[i],ss=s2[i];
			int l=0,r=s.size()-1;
			for(int j=0;j < (int)s.size();j++){
				if(s[j]!=ss[j]){
					break;
				}else{
					l++;
				}
			}
			for(int j=s.size()-1;j >= 0;j--){
				if(s[j]!=ss[j]){
					break;
				}else{
					r--;
				}
			}
			for(int j=l;j <= r;j++){
				hx[i].c1+=qp[j-l]*(s[j]-'0');
				hx[i].c2+=qp[j-l]*(ss[j]-'0');
				hx[i].idx=i;
				hx[i].c1%=mod;
				hx[i].c2%=mod;
				hx[i].c3+=qp2[j-l]*(s[j]-'0');
				hx[i].c4+=qp2[j-l]*(ss[j]-'0');
				hx[i].idx=i;
				hx[i].c1%=mod2;
				hx[i].c2%=mod2;
			}
		}
		int p=0;
		for(int i=1;i <= m;i++){
			string s,ss;
			s=s3[i],ss=s4[i];
			if(s.size()!=ss.size()) ans[i]=0;
			else{
				p++;
				int l=0,r=s.size()-1;
				for(int j=0;j < (int)s.size();j++){
					if(s[j]!=ss[j]){
						break;
					}else{
						l++;
					}
				}
				for(int j=s.size()-1;j >= 0;j--){
					if(s[j]!=ss[j]){
						break;
					}else{
						r--;
					}
				}
				hx[n+p].idx=i+n;
				for(int j=l;j <= r;j++){
					hx[n+p].c1+=qp[j-l]*(s[j]-'0');
					hx[n+p].c2+=qp[j-l]*(ss[j]-'0');
					hx[n+p].c1%=mod;
					hx[n+p].c2%=mod;
					hx[n+p].c3+=qp2[j-l]*(s[j]-'0');
					hx[n+p].c4+=qp2[j-l]*(ss[j]-'0');
					hx[n+p].c1%=mod2;
					hx[n+p].c2%=mod2;
				}
			}
		}
		sort(hx+1,hx+n+p+1,cmp);
		int y=0;
		int s=1;
		for(int i=1;i <= n+p;i++){
			if(i!=1&&(hx[i].c1!=hx[i-1].c1||hx[i].c2!=hx[i-1].c2||hx[i].c3!=hx[i-1].c3||hx[i].c4!=hx[i-1].c4)){
				y=0;
				s++;
			}
			//cout<<hx[i].c1<<' '<<hx[i].c2<<' '<<hx[i].idx<<"\n";
			if(hx[i].idx<=n){
				y++;
			}else{
				ans[hx[i].idx-n]=y;
			}
		}
		for(int i=1;i <= m;i++){
			cout<<ans[i]<<"\n";
		}
	}
	
	return 0;
}
