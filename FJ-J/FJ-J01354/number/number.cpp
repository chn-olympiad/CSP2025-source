#include<bits/stdc++.h>
using namespace std;
string s;
int a[1123456],f=1;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[f]=int(s[i])-'0';
			f++;
		}
	}sort(a+1,a+1+f,greater<int>());
	for(int i=1;i<f;i++) cout<<a[i];
	return 0;
} 
