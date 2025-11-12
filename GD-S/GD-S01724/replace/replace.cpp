#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200001][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int flag=0;
		for(int i=1;i<=n;i++){
			string tk=s[i][0]+"#"+t1;
			int k[500005]={0};
			for(int j=2;j<=tk.size();j++){
				if(tk[k[j-1]]==tk[j-1])k[j]=k[j-1]+1;
				else{
					int t=k[j-1];
					while(t){
						if(tk[t]==tk[j-1])break;
						else t=k[t];
					}
					k[j]=t+(tk[t]==tk[j-1]);
				}
				if(k[j]==s[i][0].size()){
					string t=t1;
					t.replace(j-k[j]*2-1,k[j],s[i][1]);
					if(t==t2){
						flag++;
						break;
					}
				}
			}
		}
		cout<<flag<<endl;
	}
	return 0;
}
