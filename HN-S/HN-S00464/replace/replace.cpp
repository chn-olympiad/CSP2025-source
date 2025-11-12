#include<bits/stdc++.h>
using namespace std;
const int p=13331;
const int maxn=2e5+7;
const int maxlen=5e6+7;
int n,q;
string st[maxn],sh[maxn];
unsigned long long pw[maxlen];
unsigned long long hs[maxn][3];
unsigned long long hsq1[maxlen];
unsigned long long hsq2[maxlen];
void initall(){
	for(int i=1;i<=n;i++){
		int len=st[i].size();
		for(int j=1;j<len;j++){
			hs[i][1]=hs[i][1]*p+st[i][j];
			hs[i][2]=hs[i][2]*p+sh[i][j];
		}
	}
	return ;
}
void init(string sa,string sb){
	int len=sa.size();
	for(int i=1;i<len;i++){
		hsq1[i]=hsq1[i-1]*p+sa[i];
		hsq2[i]=hsq2[i-1]*p+sb[i];
	}
	return ;
}
unsigned long long query1(int l,int r){
	return hsq1[r]-hsq1[l-1]*pw[r-l+1];
}
unsigned long long query2(int l,int r){
	return hsq2[r]-hsq2[l-1]*pw[r-l+1];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=maxlen-2;i++){
		pw[i]=pw[i-1]*p;
	}
	for(int i=1;i<=n;i++){
		cin>>st[i]>>sh[i];
		st[i]="#"+st[i];
		sh[i]="#"+sh[i];
	}
	initall();
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int len=a.size();
		int ans=0;
		a="#"+a;
		b="#"+b;
		init(a,b);
		for(int i=1;i<=len;i++){
			for(int j=1;j<=n;j++){
				int lenj=st[j].size()-1;
				if(i+lenj-1>len){
					continue;
				}
				unsigned long long op1=query1(i,i+lenj-1);
				unsigned long long op2=query2(i,i+lenj-1);
				unsigned long long w1=query1(1,i-1);
				unsigned long long w2=query2(1,i-1);
				unsigned long long w3=query1(i+lenj,len);
				unsigned long long w4=query2(i+lenj,len);
				if(op1==hs[j][1]&&op2==hs[j][2]&&w1==w2&&w3==w4){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb




3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/
