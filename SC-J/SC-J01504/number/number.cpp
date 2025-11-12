#include <bits/stdc++.h>
using namespace std;
int a[100005],n,p,j=1;
string s1;
int main(){
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='0'){
			p++;
			continue;
		}
		if(s1[i]>='1'&&s1[i]<='9'){
			n++; 
			a[j]=int(s1[i]-'0');
			j++;
		}
	} 
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	} 
	for(int i=1;i<=p;i++){
		cout<<'0';
	}
	return 0;
}