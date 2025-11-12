#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+5;
const int INF=0x3f3f3f3f;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),cnt=0;
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	if(!a[1]){
		cout<<0<<endl;
	}else{
		for(int i=1;i<=cnt;i++){
			cout<<a[i];
		}
	}
	return 0;
}

