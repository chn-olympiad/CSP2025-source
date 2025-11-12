#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=2e5+10;
int n,q;
string s1[N],s2[N];
int a[N],b[N];
signed main(){

	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int pd=1;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=s1[i].size();j<=t1.size();j++){
				string tt1=t1;
				int ppd=1;
				for(int k=j-s1[i].size();k<j;k++)
					if(tt1[k]!=s1[i][k-j+s1[i].size()])ppd=0;
				if(ppd){
//					cout<<i;
					for(int k=j-s1[i].size();k<j;k++)
						tt1[k]=s2[i][k-j+s1[i].size()];
					if(tt1==t2){
						ans++;
//						cout<<i;
						break;
					}
				}
				
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

