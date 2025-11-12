#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
LL a[1000010],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	LL len=s.size();
	for(LL i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt);
	for(LL i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
