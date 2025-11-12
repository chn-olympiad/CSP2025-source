#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[10],m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++)
		if(s[i]<='9'&&s[i]>='0'){
			int z=s[i]-48;
			a[z]++;
		}
	for(int i=9;i>0;i--)
		for(int j=1;j<=a[i];j++){
			cout<<i;
			m=1;		
		}
	if(m==1){
		for(int j=1;j<=a[0];j++){
			cout<<0;
		}
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
} 
