#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
const int N=2e6+10,inf=0x3f3f3f3f,mod=1e9+7;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;
/*

*/
int n,q;
string s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		string q1,q2;
		cin>>q1>>q2;
		if(q1.size()!=q2.size())
			{cout<<0<<"\n";continue;}
		int cnt=0;
		for(int i=0;i<q1.size();i++){
			for(int j=1;j<=n;j++){
				if(i+s1[j].size()>q1.size()) continue;
				bool flag=1;
				for(int k=0;k<s1[j].size()&&flag;k++)
					if(s1[j][k]!=q1[k+i]) flag=0;
				if(!flag) continue;
				string t=q1;
				for(int k=0;k<s1[j].size();k++) t[k+i]=s2[j][k];
				if(t==q2) ++cnt;
			}
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}

