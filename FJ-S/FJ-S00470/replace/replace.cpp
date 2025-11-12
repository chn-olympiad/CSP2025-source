#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s[100001],t[100001],x[100001],y[100001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i]>>x[i];
	for(int i=1;i<=q;i++)cin>>t[i]>>y[i];
	for(int i=1;i<=q;i++){
		string d=t[i],k=y[i];
		long long sun=0;
		for(int j=1;j<=n;j++){
			if(s[j]==d&&x[j]==k)sun+=2;}
		cout<<sun<<endl;
	}
	return 0;
}