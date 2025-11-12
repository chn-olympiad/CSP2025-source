#include<bits/stdc++.h>
#define leng 1000000
using namespace std;
string s;
int p[leng+6],zeros=0,nums=0;
bool g(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<leng;i++){
		if(s[i]>48&&s[i]<58){
			p[i]=s[i]-48;
			nums++;
		}
		else if(s[i]==48) zeros++;
	}
	sort(p,p+leng,g);
	for(int i=0;i<nums+zeros;i++){
		cout<<p[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
