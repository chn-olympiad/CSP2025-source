#include <bits/stdc++.h>
using namespace std;
int a[1000001]={-1};
bool cmp(int a,int b){
	return a>b;
}
int main(){
   	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int sum=0;
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			sum++;
			a[i]=s[i]-'0';
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
}
