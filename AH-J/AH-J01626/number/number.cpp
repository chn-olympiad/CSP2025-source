#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0;
	cin>>s;
	int len=sizeof(s);
	for(int i=0;i<len;i++){
		if(s[i]=='1')a[cnt++]=1;
		else if(s[i]=='2')a[cnt++]=2;
		else if(s[i]=='3')a[cnt++]=3;
		else if(s[i]=='4')a[cnt++]=4;
		else if(s[i]=='5')a[cnt++]=5;
		else if(s[i]=='6')a[cnt++]=6;
		else if(s[i]=='7')a[cnt++]=7;
		else if(s[i]=='8')a[cnt++]=8;
		else if(s[i]=='9')a[cnt++]=9;
		else if(s[i]=='0')a[cnt++]=0;
	} 
	sort(a,a+cnt,cmp);
	for(int i=cnt-1;i>=0;i--)cout<<a[i];
	return 0;
}
