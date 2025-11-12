#include<bits/stdc++.h>
using namespace std;
string s;
int j=1;
int a[1000004];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if('0'<=s[i] and s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j);
	for(int i=j-1;i>=1;i--){
		cout<<a[i];
	}
} 
