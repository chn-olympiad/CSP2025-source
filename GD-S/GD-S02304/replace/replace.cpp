#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005],t1,t2; 
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    while(q--){
    	cin>>t1>>t2;
    	ans=0;
    	for(int i=1;i<=n;i++){
    		int x=t1.find(s1[i]);
    		string t=t1;
    		for(int j=0;j<s1[i].size();j++){
    			t[x+j]=s2[i][j];
			}		
    		if(t==t2) ans++;
		}
		cout<<ans<<endl;
	}
	//我是浦帅的忠实粉丝 
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
