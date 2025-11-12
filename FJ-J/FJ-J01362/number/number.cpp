#include<bits/stdc++.h>
using namespace std;
string s;
short a[10000005];
int num;
bool q(int a,int b){
	return a<b;
}
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s[num];
	long long l=s.length();
	cout<<s[l];
	for(int i=0;i<l;i++){
		if(s[i]=='0'&&s[i]<=9){
			a[s[i]-'0']++;
		}
	
		for(int i=1;i<=10;i++){
			for(int j=1;j<=a[i];j++){
				a[num++]=s[i]-'0';
			}
		}
	}
	sort(a+1,a+num+1,q);
	for(int i=1;i<=num;i++){
		cout<<a[i];
	}
	return 0;
}
