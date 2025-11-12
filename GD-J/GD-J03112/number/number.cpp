#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string str;
int cnt,a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9'){
			cnt++;
			a[cnt]=str[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,greater<int>());
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
