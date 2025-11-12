#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	getline(cin,a);
	char num[1000010];
	int la=a.length(),ni=0;
	for(int i=0;i<la;i++){
		if(a[i]>='0' && a[i]<='9') num[ni++]=a[i];
	}
	sort(num,num+ni);
	for(int i=ni-1;i>=0;i--) cout<<num[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
