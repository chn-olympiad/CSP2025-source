#include<bits/stdc++.h>
using namespace std;
int num,a[1000000];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	num=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			num++;
			a[num]=s[i]-'0';
		}
	}
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
