#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
const int N=1e6+100;
int a[N];
int op;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++op]=(int)(s[i]-'0');
		}
	}
	sort(a+1,a+1+op,cmp);
	for(int i=1;i<=op;i++){
		cout<<a[i];
	}
	
	
	
	
	return 0;
}
