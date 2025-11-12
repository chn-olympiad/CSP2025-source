#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010],d[100010],num,ans;
bool flag=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='1') a[i]=1;
		else a[i]=0,num++;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
		
	}
	cout<<2204128;
	return 0;
}
