#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[1000010],cnt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	time_t start=clock();
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,greater<ll>());
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
//	time_t duration=clock()-start;
//	cout<<'\n'<<duration<<"ms";
	return 0;
}
