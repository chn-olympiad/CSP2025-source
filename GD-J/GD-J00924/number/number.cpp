#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define PLL pair<long long,long long>
#define PB push_back
const int N=114514;
ll m,n;
ll a[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll lens=s.size();
	for(int i=0;i<lens;i++) if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(a[i]){
			printf("%lld",i);
			a[i]--;
		}
	return 0;
	}
/**/

