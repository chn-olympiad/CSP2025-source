#include<bits/stdc++.h>
using namespace std;
long long a[1000001],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i;--i){
		cout<<a[i];
	}
	return 0;
} 
