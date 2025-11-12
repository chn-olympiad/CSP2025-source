#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,q;
string s1[N],s2[N];
string q1,q2;


int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>q1>>q2;
		int t=s1[i].size();
		for(int j=0;j<q1.size()-t;j++){
			int h=1;
			for(int k=0;k<s1[i].size();k++)if(q2[k+j]!=s2[i][k])h=0;
			if(h){
				int vis=1;
				for(int k=0;k<j;k++)if(q1[k]!=q2[k])vis=0;
				for(int k=j+t;k<q1.size();k++)if(q1[k]!=q2[k])vis=0;
				if(vis==1)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}

