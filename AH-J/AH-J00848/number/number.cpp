#include<bits/stdc++.h>
using namespace std;
string s;
int n=0,a[5000006];
bool cmp(int x,int y){
	return x>=y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i = 0;i < len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[n]=(s[i]-'0');
		}
	}
	sort(a+1,a+n+1,cmp);
	bool f=0;
	for(int i = 1;i <= n;i++){
		if(a[i]!=0||i==n||f){
			f=1;
			cout<<a[i];
		}
	}
	return 0;
}
