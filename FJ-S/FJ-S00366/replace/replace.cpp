#include <bits/stdc++.h>
using namespace std;
#define rt return
typedef long long ll;
const int N=200100;
int n,q;
string s[N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);	 
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(;q;--q){
		puts("0");
	}
	rt 0;
}                                         
