#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+1;
char s[N];
int a[N],n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
ll len=strlen(s);
for(register ll i=0;i<len;i++)
{
	if(s[i]>='0'&&s[i]<='9'){
		a[n]=s[i]-'0';
		n++;
	}
}
sort(a,a+n,cmp);
for(register int i=0;i<n;i++){
	cout<<a[i];
}
return 0;
}
