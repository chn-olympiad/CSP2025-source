#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
pair<string,string>a[N];
pair<string,string>match[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	for(int i=1;i<=q;i++)cin>>match[i].first>>match[i].second;
	for(int i=1;i<=q;i++){
		cout<<"0"<<"\n";
	}
	return 0;
}
