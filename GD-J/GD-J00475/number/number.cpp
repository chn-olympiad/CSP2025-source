#include <bits/stdc++.h>
using namespace std;
char ch[1000005];
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size(),x=0;
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			x++;
			ch[x]=s[i];
		}
	}
	sort(ch+1,ch+x+1,cmp);
	for(int i=1;i<=x;i++){
		cout<<ch[i];
	}
	cout<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
