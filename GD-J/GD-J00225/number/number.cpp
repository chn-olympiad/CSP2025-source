#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N],n;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9'){
			a[++n]=c-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--) cout<<a[i];
}
