#include<bits/stdc++.h>
#define ff(i,n) for(int i=1;i<=n;i++) 
#define int long long
using namespace std;
const int N=2e6+10,M=1e6,mod=993644353; 
int i,j,k,n,m,x,y,tot;
char s[N];
int a[N];
main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	n=strlen(s+1);
	ff(i,n){
		if('0'<=s[i]&&s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	} 
	sort(a+1,a+1+tot);
	for(i=tot;i;i--)cout<<a[i];
}
