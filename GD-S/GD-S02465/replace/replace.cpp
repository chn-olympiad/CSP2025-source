#include<bits/stdc++.h>
using namespace std;
string s1[200010],s2[200010];
unsigned long long pw[5000010];
unsigned long long hsh[200010][2],hs[200010][2];
string t1,t2;
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=5000000;i++){
		pw[i]=pw[i-1]*131;
	}
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++){
			hsh[i][0]=hsh[i][0]*131+(unsigned long long)(s1[i][j]-'a'+1);
		}
		for(int j=0;j<s1[i].size();j++){
			hsh[i][1]=hsh[i][1]*131+(unsigned long long)(s2[i][j]-'a'+1);
		}
//		cout<<hsh[i][0]<<","<<hsh[i][1]<<"\n";
	}
	while(q--){
		cin>>t1>>t2;
		t1=' '+t1;
		t2=' '+t2;
		for(int i=1;i<t1.size();i++){
			hs[i][0]=hs[i-1][0]*131+t1[i]-'a'+1;
			hs[i][1]=hs[i-1][1]*131+t2[i]-'a'+1;
//			cout<<hs[i][0]<<","<<hs[i][1]<<"\n";
		}
		int ans=0;
		
		for(int j=1;j<t1.size();j++){
//			cout<<hs[j-1][0]<<" "<<hs[j-1][1]<<"\n";
			if(hs[j-1][0]!=hs[j-1][1])continue;
			for(int i=1;i<=n;i++){
				if(j+s1[i].size()-1>=t1.size())continue;
				unsigned long long h1=hs[j+s1[i].size()-1][0]-hs[j-1][0]*pw[s1[i].size()];
//				cout<<h1<<"::\n";
				if(h1!=hsh[i][0])continue;
				unsigned long long h2=hs[j+s1[i].size()-1][1]-hs[j-1][1]*pw[s1[i].size()];
//				cout<<h2<<":::\n";
				if(h2!=hsh[i][1])continue;
				unsigned long long h3=hs[t1.size()-1][0]-hs[j+s1[i].size()-1][0]*pw[t1.size()-j-s1[i].size()];
				unsigned long long h4=hs[t2.size()-1][1]-hs[j+s1[i].size()-1][1]*pw[t1.size()-j-s1[i].size()];
//				cout<<h3<<","<<h4<<"::::\n";
				if(h3!=h4)continue;
				ans++;
			}
		}
		cout<<ans<<"\n";
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

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

1024n+1024*5n=6144n 
11n+10n*10+9n*45...+n
*/
