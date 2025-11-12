#include<bits/stdc++.h>
using namespace std;
int a[1000006];
char s[1000006];
bool cmp(int m,int n){
	return m>n;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int len=0,sum=0;
	while(cin>>s[len++]);
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)cout<<a[i];
	cout<<"\n";
	
	return 0;
} 
