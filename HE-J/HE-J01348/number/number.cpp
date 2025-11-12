#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int len=s.size(),m=0;
	for(int i=0;i<len;++i){
		char t=s[i];
		if(t>='0'&&t<='9') a[++m]=t-'0';
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;++i) cout<<a[i];
	fclose(stdin);fclose(stdout);
	return 0;
}
