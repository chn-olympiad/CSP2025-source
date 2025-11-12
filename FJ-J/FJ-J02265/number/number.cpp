#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string str;
int len,n,a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	len=str.length();
	for(int i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9'){
			n++;a[n]=str[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
} 
