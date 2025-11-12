#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,q;
string s1[N],s2[N],t1[N],t2[N];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string q1=t1[i],q2=t2[i];
		if(q1.size()!=q2.size()){
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<(int)q1.size();i++){
			for(int j=i;j<(int)q1.size();j++){
				string l1=q1.substr(0,i);
				string r1=q1.substr(j+1,n-j+1);
				string l2=q2.substr(0,i);
				string r2=q2.substr(j+1,n-j+1);
				string tmp1=q1.substr(i,j-i+1);
				//cout<<l1<<' '<<tmp1<<' '<<r1<<'\n';
				string tmp2=q2.substr(i,j-i+1);
				if(l1!=l2||r1!=r2) continue;
				for(int k=1;k<=n;k++){
					if(tmp1==s1[k]&&tmp2==s2[k]) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

