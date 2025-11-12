#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
bool cmp(int x,int y){
	return x>y;
}
string s;
int a[N],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	if(l==1) return cout<<s[0]-'0',0;
	for(int i=0,j=l-1;i<j;i++,j--){
		if(s[i]>='0'&&s[i]<='9') a[++k]=s[i]-'0';
		if(s[j]>='0'&&s[j]<='9') a[++k]=s[j]-'0';
	}
	if(l%2==1) a[++k]=s[(l-1)/2]-'0';
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++) cout<<a[i];
	return 0;
}
 
