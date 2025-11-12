//code by ZXZMC
//T3 AK ME 10pts
//·ÅÆúË¼¿¼¡£¡£¡£ 
#include<bits/stdc++.h>
#define CSP using
#define AK namespace
#define ME std;
CSP AK ME
const int N=1e4+10;
int n,q;
string s[N][5];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		int lt=t1.size();
		for(int i=1;i<=n;i++){
			int ls=s[i][1].size();
			for(int j=0;j<=lt-ls;j++){
				string x=t1.substr(0,j);
				string y=t1.substr(j,ls);
				string z=t1.substr(j+ls,lt-(j+ls)+1);
//				int l=j,r=j+ls-1;
//				cout<<x<<' '<<y<<' '<<z<<endl;
				if(y==s[i][1]){
//					cout<<"OHYES\n";
//					cout<<"OLD:"<<x+y+z<<" NEW:"<<x+s[i][2]+z<<endl; 
					if(t2==x+s[i][2]+z) ans++;
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

*/
