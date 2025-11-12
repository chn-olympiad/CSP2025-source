#include<bits/stdc++.h>
using namespace std;
long long a[10000005],x=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			a[x]=s[i]-48;
		}
 	}
	sort(a+1,a+1+x);
	for(int i=x;i>=1;i--){
		cout<<a[i];
	}
} 
