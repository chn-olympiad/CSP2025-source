#include<bits/stdc++.h>
using namespace std;
string s;
int ss,a[1000010],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	ss=s.size();
	for(int i=0;i<ss;i++){
		if(s[i]>='0' and s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,greater<int>());
	for(int i=1;i<=cnt;i++){
		cout <<a[i];
	}
	return 0;
}
