#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int a[1000001]={0};
int num=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i]-'0';
			num++;
		}
	}
	sort(a,a+num);
	for(int i=num-1;i>=0;i--){
		cout<<a[i];
	}
	return 0; 
} 
