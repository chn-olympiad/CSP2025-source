#include<bits/stdc++.h>
using namespace std;
long long n,m,c[510],chen;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.size();
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(c[i]+c[j]==n)chen++;
		}
	}
	cout<<chen<<endl;
	return 0;}
	                      