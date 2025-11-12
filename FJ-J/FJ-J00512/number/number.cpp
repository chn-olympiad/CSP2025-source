#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000005
string s;
int t=0;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	else{
		for(int i=1;i<=t;i++){
			cout<<a[i];
		}
	}
	return 0;
}
