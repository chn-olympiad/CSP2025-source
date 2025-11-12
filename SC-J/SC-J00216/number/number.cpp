#include<bits/stdc++.h>
using namespace std;
string s;
int l,a[1000010],sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	l = s.length();
	for(int i=0;i<l;i++)
		if(s[i]>='0' && s[i]<='9')
			a[++sum] = s[i]-'0';
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++) cout << a[i];
	return 0;
}