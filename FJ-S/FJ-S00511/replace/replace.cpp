#include <bits/stdc++.h>
#define ull long long
using namespace std;

const int N=2e5+5;
const int L=5e6+5;
int n,q;
string a[N],b[N];
const int P=131;
unordered_map<ull,ull>m;
ull h1[L];
ull h2[L];

ull Hash(string oo){
	ull h=0;
	int len=oo.length();
	for(int i=0;i<len;++i)
		h=h*P+oo[i];
	return h;
}


ull H1(int l,int r){
	return h1[r]-h1[l-1]*pow(P,r-l+1);
}

ull H2(int l,int r){
	return h2[r]-h2[l-1]*pow(P,r-l+1);
}

int main(){

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		ull x=Hash(a[i]),y=Hash(b[i]);
		m[x]=y;
	}
	
	string s,t;
	while(q--){
		int cnt=0;
		cin>>s>>t;
		int ls=s.length();int lt=t.length();
		if(ls!=lt){printf("0\n");continue;}
		int l=0,r=0;bool f=0;
		for(int i=0;i<ls;++i){
			if(s[i]!=t[i]){if(!f)l=i,f=1;r=i;}
			h1[i]=h1[i-1]*P+s[i];
			h2[i]=h2[i-1]*P+t[i];
		}
		//cout<<H1(2,3)<<" "<<Hash("bc")<<"\n";
		for(int i=l;i>=0;--i){
			for(int j=r;j<ls;++j){
				ull x=H1(i,j);
				ull y=H2(i,j);
				//cout<<x<<" "<<y<<"\n";
				if(m[x]==y){
					++cnt;
					//cout<<"ptptp\n";
				}
			}
		}
		cout<<cnt<<"\n";
		for(int i=1;i<ls;++i)
			h1[i]=0,h2[i]=0;
	}
	
	return 0;
}
