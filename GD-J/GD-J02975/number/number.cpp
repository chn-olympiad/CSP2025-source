#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),num=1;
	for(int i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i]-'0';
			num++;
		}
	}
	sort(a+1,a+num+1);
	for(int i=num;i>=2;i--){
		cout<<a[i];
	} 
	return 0;
} 
