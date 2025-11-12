#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N],n,tot=0;
string s;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+1+tot,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=tot;i++){
		
		cout<<a[i];
	}
	return 0;
	}

