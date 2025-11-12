#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int k=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s="";
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i]))a[++k]=s[i]-'0';
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	return 0;
} 
