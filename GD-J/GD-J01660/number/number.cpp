#include<bits/stdc++.h>
using namespace std;
string s;
int num;
int a[1000010];
int b;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	num=s.length();
	for(int i=0;i<num;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<10){
			a[i]=s[i]-'0';
			b++;
		}
	}
	sort(a,a+num,cmp);
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	return 0;
}
