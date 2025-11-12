#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	string s1,s2;
}a[N];
int n,q;
int ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i].s1>>a[i].s2;
	while(q--){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())cout<<"0\n";
		else {
			for(int i=1;i<=n;i++){
				int j=0;
				int id1=t1.find(a[i].s1);
				if(id1==-1)continue;
				string tt1=t1;
				tt1.erase(id1,a[i].s1.size());
				tt1.insert(id1,a[i].s2);
				if(tt1==t2)ans++;
			}
			cout<<ans<<'\n';
		}
	}

	return 0;
}

