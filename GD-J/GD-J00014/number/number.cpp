#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000001;
char s[MAXN];
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s,s+MAXN,cmp);
	for(int i=0;s[i]!='\0';i++)if(s[i]>='0'&&s[i]<='9')cout<<s[i];
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
