#include<bits/stdc++.h>
using namespace std;
string s;
int a[100001]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length(),k;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			k=(int)s[i]-'0';
			a[k]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
