#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt;
bool cmp(int x,int y) {
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>s;
	int len=s.length();
	for(int i=0; i<len; i++) {
		int k=s[i]-'0';
		if(k>=0&&k<=9)a[++cnt]=k;
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1; i<=cnt; i++) cout<<a[i];
	cout<<"\n";
	return 0;
}
