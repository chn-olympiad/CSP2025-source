#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q;
string s1[N],s2[N],s,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		cin>>s>>t;
//		cout<<s<<" "<<t<<endl;
		int ans=0;
		for(int i=1;i<=n;i++){
			int x=s.find(s1[i]);
//			cout<<i<<endl;
			if(x<s.size()){
				string k=s;
				k.replace(x,s1[i].size(),s2[i]);
//				cout<<k;
				if(k==t){
					ans++;
//					cout<<" yes";
				}else{
//					cout<<" no";
				}
			}else{
//				cout<<"no";
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	}
}

