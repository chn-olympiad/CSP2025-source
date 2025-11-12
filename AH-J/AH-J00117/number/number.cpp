#include<iostream>
#include<algorithm>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	int cnt=0;
	long long len=s.length();
	for(int i=0;i<len;i++){
		if(isdigit(s[i]))
			a[cnt++]=s[i]-'0';
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--)
		cout<<a[i];
	return 0;
}
