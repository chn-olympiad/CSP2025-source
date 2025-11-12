#include<bits/stdc++.h>
using namespace std;
int n,m,c[505]={-1},f[505]={0},p[505]={0};
long long sum;
bool s[505];
char s1[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		s[i+1]=s1[i]-'0';
	}
	int n2=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	return 0;
}
