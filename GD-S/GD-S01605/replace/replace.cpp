#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string s[n][2];
    int len[n];
    for(int i=0;i<n;i++){
    	cin>>s[i][0]>>s[i][1];
    	len[i]=s[i][0].length();
	}
	int ans[q];
	for(int i=0;i<q;i++){
		ans[i]=0;
    	string tg,ts;
		cin>>tg>>ts;
		if(tg.length() != ts.length()){
			ans[i]=0;
			continue;
		}
		if(tg==ts){
			ans[i]=0;
			continue;
		}
		int dfbgn=tg.length(),dfed=0;
		for(int j=0;j<tg.length();j++){
			if(tg[j]!=ts[j]){
				dfed=j;
				if(j<dfbgn){
					dfbgn=j;
				}
			}
		}
		for(int k=0;k<n;k++){
			if(len[k]<=dfed-dfbgn){
				continue;
			}
	 		for(int j=dfed-len[k]+1;j<=dfbgn;j++){
	    		string nowx="";
    			string nowy="";
				for(int rd=j;rd<j+len[k];rd++){
			    	nowx=nowx+tg[rd];
				    nowy=nowy+ts[rd];
				}
    			if(nowx==s[k][0] && nowy==s[k][1]){
    				ans[i]++;
    			}
			}
		}
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
