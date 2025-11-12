#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],num=0;
bool cmp(int p1,int p2){
	return p1>p2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num++;
			a[num]=s[i]-'0';
		}
	}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		cout<<a[i];
	}
	return 0;
}
