#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],flag;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[flag]=int(s[i]-'0');
			flag++;
		}
	}
	sort(a,a+flag,cmp);
	for(int i=0;i<flag;i++){
		cout<<a[i];
	}
	return 0;
}