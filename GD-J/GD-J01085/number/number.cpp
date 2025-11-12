#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
string s;
int n,a[N],cnt;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
