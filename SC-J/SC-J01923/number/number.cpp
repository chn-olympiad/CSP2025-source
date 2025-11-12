#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int c;
char a[1000005];
bool cmp(char x,char y){
	return x>y;
} 
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[++c]=s[i];
	}
	sort(a+1,a+c+1,cmp);
	for(int i=1;i<=c;i++)cout<<a[i];
	return 0;
}