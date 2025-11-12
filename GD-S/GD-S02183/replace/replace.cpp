#include<bits/stdc++.h>
#define M 100010
#define N 2100
using namespace std;
int n,q;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string q1,q2,ori;
		cin>>ori>>q2;q1=ori;
		int ans=0,l=q1.size();
		for(int i=1;i<=n;i++){
			int len=s[i][1].size();
			int pos=q1.find(s[i][1]);
			if(pos==-1)continue;
			for(int j=pos;j<=l-len;j++){
				for(int k=j;k<len+j;k++){
					q1[k]=s[i][2][k-j];
				}
				if(q1==q2)ans++;
				q1=ori;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
