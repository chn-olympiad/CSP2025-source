#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';	
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) cout<<a[i];
}
