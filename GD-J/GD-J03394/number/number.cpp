#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
string s;
int sum=0;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(int(s[i]-'0')>=0&&int(s[i]-'0')<=9){
			a[sum++]=s[i];
		}
	}
	sort(a,a+sum,cmp);
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
}//9:01 solve question 1
