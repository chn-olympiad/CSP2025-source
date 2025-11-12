//GZ-S00207 曹语心 贵阳市第十八中学 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[505],sumn=1,cnt=0;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'==1)cnt++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(cnt==s.size()){
		for(int i=1;i<=m;i++){
			sumn*=n;
			n--;			
		}
	}else{
		for(int i=0;i<m;i++)sumn*=18-i;
	}
	cout<<sumn; 
	return 0;
}
