#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<1000005;i++){
		a[i]=INT_MAX;
	}
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++){
	//	int sz=s[i]-'0';
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+s.size());
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
