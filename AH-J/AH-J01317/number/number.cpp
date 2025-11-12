#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7,inf=1e18;
string s;
int a[N];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int o=s.size();
    int sum=0;
    for(int i=0;i<o;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++sum]=(s[i]-'0');
		}
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--) cout<<a[i];
	cout<<"\n";
    return 0;
}
