#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int x,int y){
	return x>y;
};
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a[10001],cnt=0;
	for(int i = 0;i <= s.length();i++){
		if(isdigit(s[i])){
			if(int(s[i])==48){
				a[i]=1;
			}
			else {
				a[i]=int(s[i])-48;
			}
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
