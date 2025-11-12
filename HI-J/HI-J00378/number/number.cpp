#include<bits/stdc++.h>
using namespace std;
int a=0;
int n[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(int(s[i])>=48 and int(s[i])<=57){
			n[a]=s[i]-48;
			a+=1;
		}
	}
	sort(n,n+a,cmp);
	for(int i=0;i<a;i++){
		cout<<n[i];
	}
	return 0;
} 
