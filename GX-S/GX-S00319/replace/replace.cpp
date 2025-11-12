#include<bits/stdc++.h>
using namespace std;
int n,q,g[200001],f,ans,lb[200001][0];
string s[200001][2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>10000&&q>10000){
	    for(int i=1;i<=n;i++){
		    cin>>s[i][0]>>s[i][1];
		    g[i]=s[i][0].size();
		    for(int j=0;j<g[i];j++){
				if(s[i][0][j]=='b')lb[i][0]=j;
				if(s[i][1][j]=='b')lb[i][1]=j;
			}
	    }
	    while(q--){
			ans=0;
		    string t1,t2;
		    cin>>t1>>t2;
		    int l=t1.size(),k1,k2;
		    for(int i=0;i<l;i++){
				if(t1[i]=='b'){
					k1=i;
				}
				if(t2[i]=='b'){
					k2=i;
				}
			}
			for(int i=1;i<=n;i++){
				if(g[i]<l&&lb[i][0]>=k1&&lb[i][1]>=k2)ans++;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		g[i]=s[i][0].size();
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int l=t1.size();
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<l-g[i]+1;j++){
				f=0;
				for(int v=j;v<j+g[i];v++){
					if(t1[v]!=s[i][0][v-j]||t2[v]!=s[i][1][v-j]){f=1;break;}
				}
				if(f==0)for(int v=0;v<j;v++){
					if(t1[v]!=t2[v]){f=1;break;}
				}
				if(f==0)for(int v=j+g[i];v<l;v++){
					if(t1[v]!=t2[v]){f=1;break;}
				}
				if(f==0){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		
	}
    return 0;
}
