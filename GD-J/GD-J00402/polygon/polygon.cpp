#include<iostream>
using namespace std;
const int MAXN=5e3+10;
int s[MAXN];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	if(n<3)
		cout<<0;
	else if(n==3){
		if(max(s[1],max(s[2],s[3]))*2 < s[1]+s[2]+s[3])
			cout<<1;
		else
			cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
} 













/*1!5!
			Ð¡RÏ²»¶ÍæÐ¡¹÷Ä¾*/ 
