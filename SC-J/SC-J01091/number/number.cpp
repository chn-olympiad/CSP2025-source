#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
string s;
int a[N],idx;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')
			a[++idx]=s[i]-'0';
	}
	sort(a+1,a+1+idx);
	for(int i=idx;i>=1;i--) cout<<a[i];
	return 0;
}