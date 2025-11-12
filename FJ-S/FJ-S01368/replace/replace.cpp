#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N],t1,t2;
int	main( ){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++){
			string st=t1;
			int ide=st.find(s1[j]);
			if(ide>=0){
//				st.replace(ide,ide+s2[j].size()-1,st,s2[j]);
				for(int k=0;k<s2[j].size();k++){
					st[k+ide]=s2[j][k];
				}
//				cout<<"ide"<<ide<<" ";				
//				cout<<"st"<<st<<" "; 
				if(st==t2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
