#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int l;
const int N=1e6+1001;
char ans[N],s[N];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ans;
	int len=strlen(ans);
	for(int i=0;i<len;i++){
		if(ans[i]>='0'&&ans[i]<='9'){
			s[++l]=ans[i];
		}
	}
	sort(s+1,s+l+1,cmp);
	for(int i=1;i<=l;i++)cout<<s[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
