#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
long long l,pos;
int a[N];
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if((s[i]-'0')>=0&&(s[i]-'0')<=9){
			pos++;
			a[pos]=s[i]-'0';
		}
	}
	if(pos==l){
		sort(s.begin(),s.end(),cmp);
		cout<<s;
		return 0;
	}
	sort(a+1,a+pos+1,greater<int>());
	for(int i=1;i<=pos;i++){
		printf("%d",a[i]);
	}
	return 0;
}
