#include<bits/stdc++.h>
using namespace std;
int a[10000010],n=1;
bool func(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=(int)(s[i]-'0');
			n++;
		}
	}
	sort(a+1,a+n,func);
	if(a[1]==0)cout<<0;
	else for(int i=1;i<=n-1;i++)cout<<a[i];
	return 0;
}
