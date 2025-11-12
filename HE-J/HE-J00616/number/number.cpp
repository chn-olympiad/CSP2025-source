#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int a[1000001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	int cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-48;
			cnt++;
		}
	}
	sort(a,a+len,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

