#include<bits/stdc++.h>
using namespace std;
int a[1000005],j=0;
int main(){
	string s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		printf("%d",a[i]);
	}
	return 0;
} 
