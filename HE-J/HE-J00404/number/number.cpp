#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
char a[1000010],b[1000010],cnt=0,len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9') b[cnt++]=a[i];
	}
	sort(b,b+cnt,cmp);
	cout<<b;
	return 0;
}
