#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=5e3+5,HA=135;
int n,q;
string a[N][2];
ull h[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
		ull h1=0,h2=0;
		int l=a[i][0].size();
		for(int j=0;j<l;j++)h1=h1*HA+a[i][0][j]-'a';
		for(int j=0;j<l;j++)h2=h2*HA+a[i][1][j]-'a';
		h[i][0]=h1;h[i][1]=h2;
	}
	for(int t=1;t<=q;t++){
		string s1,s2;cin>>s1>>s2;
		int js=0;
		if(s1.size()!=s2.size()){cout<<0;continue;}
		int len=s1.size();
		ull h1=0,h2=0;
		for(int i=-1;i<len;i++){
			if(i>=0)h1=h1*HA+s1[i]-'a';
			if(i>=0)h2=h2*HA+s2[i]-'a';
			if(h1!=h2)break;
			for(int j=1;j<=n;j++){
				if(i+(int)a[j][0].size()>=len)continue;
				ull nh1=0,nh2=0;
				for(int k=i+1;k<=i+(int)a[j][0].size();k++)nh1=nh1*HA+s1[k]-'a';
				for(int k=i+1;k<=i+(int)a[j][0].size();k++)nh2=nh2*HA+s2[k]-'a';
				int fl=0;
				if(nh1==h[j][0]&&nh2==h[j][1])fl=1;
				if(!fl)continue;
				nh1=nh2=0;
				for(int k=i+(int)a[j][0].size()+1;k<len;k++)nh1=nh1*HA+s1[k]-'a';
				for(int k=i+(int)a[j][0].size()+1;k<len;k++)nh2=nh2*HA+s2[k]-'a';
				if(nh1!=nh2)continue;
				js++;
			}
		}
		cout<<js<<'\n';
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/