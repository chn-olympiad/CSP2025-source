#include<bits/stdc++.h>
using namespace std;
char s1[1000010],s2[1000010];
long long idx;
bool f;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	int len=strlen(s1);
	for(int i=0;i<len;i++)
		if(isdigit(s1[i])){
			s2[idx++]=s1[i];
			if(s1[i]!='0') f=true;
		}
	if(!f){
		cout<<0;
		return 0;
	}
	sort(s2,s2+idx,cmp);
	cout<<s2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
