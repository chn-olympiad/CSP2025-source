#include<iostream>
#include<algorithm>
using namespace std;
string s;
int a[1000005],cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[i]=s[i]-'0',cnt++;
	sort(a,a+s.size(),cmp);
	for(int i=0;i<cnt;i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
