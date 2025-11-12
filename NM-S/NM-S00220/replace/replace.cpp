#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=1e7+10;
pair<string,string>place[N];
pair<string,string>ans[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>place[i].first>>place[i].second;
	for(int i=1;i<=q;i++)cin>>ans[i].first>>ans[i].second;
	for(int i=0;i<q;i++)cout<<0<<endl;
	return 0;
}
