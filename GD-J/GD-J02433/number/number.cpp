#include<bits/stdc++.h>
using namespace std;
int const N=1e6+5;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int tot=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[++tot]=(s[i]-'0');
	}
	sort(a+1,a+tot+1,cmp);
	if(a[1]==0)cout<<0;
	else{
		for(int i=1;i<=tot;i++)cout<<a[i];
	}
	return 0;
}
