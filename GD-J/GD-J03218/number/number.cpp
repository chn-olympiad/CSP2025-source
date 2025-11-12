#include "bits/stdc++.h"
using namespace std;
string str;
int cnt;
int sorts[1000001];
int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<(int)str.length();i++)
		if(str[i]>='0' && str[i]<='9') sorts[++cnt]=str[i]-'0';
	sort(sorts+1,sorts+cnt+1);
	for(int i=cnt;i;i--) cout<<sorts[i];
	fclose(stdin);
	fclose(stdout);
}
