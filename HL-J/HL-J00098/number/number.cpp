#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int cnt=0;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	while(cnt--) cout<<a[cnt+1];
	return 0;
}

