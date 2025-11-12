#include<iostream>
#include<cmath> 
#include<cstdio> 
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
char s[1005],an[1005];
int i,I,ans;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s[i]){
		i++;
	
	}
	int len=i;
	for(int j=0;j<len;j++){
		if(s[j]>='0'&&s[j]<='9'){
			an[I]=s[j];
			I++;
		}
	}
		
	sort(an,an+I,cmp);
	for(int j=0;j<I;j++){
	 
		int x=an[j]-48;
		ans=ans*10+x;
		}
		cout<<ans;
	return 0;
}