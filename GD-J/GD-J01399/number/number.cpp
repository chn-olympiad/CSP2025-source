#include<bits/stdc++.h>
using namespace std;
int num[100001];
char s[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=sizeof(s);
	int len2=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[len2]=s[i]-'0';
			len2++;
		}
	}
	sort(num,num+len2);
	for(int i=len2-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
