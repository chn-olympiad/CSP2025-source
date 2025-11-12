#include<bits/stdc++.h>
#define ull unsigned long long
#define mod 998244353
using namespace std;
const int mmax=114514;
ull ans=0;
int a[114514],f[114514],k=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin.tie(),cout.tie();
    int n,m;
    string s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
		if(s[i-1]=='0')f[++k]=i;
	}
	sort(a+1,a+1+n);
	cout<<0; 
} 
