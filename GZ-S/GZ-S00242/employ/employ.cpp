//GZ-S00242	贵阳市第三实验中学	李金泽 
#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,p,sum,c[1000];
string s;
bool t[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0)sum++;
	}
	for(int i=1;i<=s.size();i++)t[i]=s[i]=='1'? 0 : 1;
	cout<<sum%19;
	return 0;
}
