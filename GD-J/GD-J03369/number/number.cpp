#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N];
string s;
int tot;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++tot]=s[i]-'0';
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++)cout<<a[i];
	return 0;
} 
