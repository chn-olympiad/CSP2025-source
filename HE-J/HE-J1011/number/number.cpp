#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000003];
	char a[1003]={0};
	cin>>s;
	int e=strlen(s);
	for(int i=0;i<e;i++){
		if(s[i]>='0'&&s[i]<='9') a[i]=s[i];
	}
	sort(a,a+e,cmp);
	for(int i=0;i<e;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
