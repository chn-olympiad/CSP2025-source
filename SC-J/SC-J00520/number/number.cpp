#include<bits/stdc++.h>
using namespace std;
string s;char c[1000006];
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int z=0;cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')c[z++]=s[i];
	sort(c,c+z,cmp);
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 