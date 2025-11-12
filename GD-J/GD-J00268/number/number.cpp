#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000010];
	cin>>s;
	int ex=0;
	int m=strlen(s);
	for(int i=0;i<m;i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			a[ex++]=s[i]-'0';
		}
	}
	sort(a,a+ex,cmp);
	for(int i=0;i<ex;i++){
		cout<<a[i];
	}
	return 0;
} 
