#include<bits/stdc++.h>
using namespace std;
const int Mx=2e5+100;
string t1,t2,s[Mx][4];
int n;
int sv(){
	cin>>t1>>t2;
	int n1=t1.size(),n2=t2.size();
	t1=" "+t1;t2=" "+t2;
	if(n1!=n2)return 0;
	int ans=0;
    for(int i=1;i<=n1;i++){
    	for(int j=1;j<=n;j++){
    		int tp=s[j][1].size();
    		string tmp=t1;
    		///try::
    		if(i+tp-1<=n1){
    			int fl=0;
    			int tp=s[j][1].size();
    			for(int t=i;t<=i+tp-1;t++){
    				if(t1[t]!=s[j][1][t-i]){
    					fl=1;
    					break;
					}
				}
				if(fl==1)continue;
				for(int t=i;t<=i+tp-1;t++){
    				tmp[t]=s[j][2][t-i];
				}
				if(tmp==t2)ans++;
				tmp=t1;
			}
		}
	}
	return ans;
}
int q;
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cout<<sv()<<"\n";
	}
}
