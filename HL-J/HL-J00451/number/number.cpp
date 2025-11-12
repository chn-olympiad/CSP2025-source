#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
int cnt;
bool cmp(int x,int y) {
	return x>y;
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++) {
		if(s[i]>='0' && s[i]<='9')
			a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
		cout<<a[i];
	//cout<<"\n";
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
