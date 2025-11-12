#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	int p=0;
	cin>>n>>m;
	string a[101],b[101];
	string c[101],d[101];
	for(int i=1;i<=n;i++)	cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)   cin>>c[i]>>d[i];
	for(int i=1;i<=n;i++){
		if(a[i].size()==c[i].size()||b[i].size()==d[i].size()) p++;
		cout<<p;
	}
	return 0;
}
