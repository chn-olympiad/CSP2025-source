#include<bits/stdc++.h>
using namespace  std;
#define int long long
const int N=1e7+7;
int a[N];
int cmp(int a,int b){return a>b;}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	int n=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++) cout<<a[i];
	exit(0);
}
