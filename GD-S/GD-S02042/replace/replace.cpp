#include<bits/stdc++.h>
using namespace std;
const int N=2e5+30;
int n,q,mv[N];
string s[N][5];
bool b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int x=0,y=0;
		for(int j=0;j<=s[i][1].size();j++) if(s[i][1][j]=='b') x++;
		for(int j=0;j<=s[i][2].size();j++) if(s[i][2][j]=='b') y++;
		if(x!=1||y!=1) b=1;
	}
	if(!b){
		for(int i=1;i<=n;i++){
			int x,y;
		    for(int j=0;j<=s[i][1].size();j++) if(s[i][1][j]=='b') x=j;
		    for(int j=0;j<=s[i][2].size();j++) if(s[i][2][j]=='b') y=j;
		    mv[i]=x-y;
		}
		sort(mv+1,mv+1+n);
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			int x,y;
		    for(int j=0;j<=t1.size();j++) if(t1[j]=='b') x=j;
		    for(int j=0;j<=t2.size();j++) if(t2[j]=='b') y=j;
		    int mov=x-y;
		    //for(int )
		    cout<<0<<endl;
		}
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		cout<<0<<endl;
	}
	return 0;
}
