#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],cnt=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-'0';
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

