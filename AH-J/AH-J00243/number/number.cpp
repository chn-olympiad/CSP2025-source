#include<bits/stdc++.h> 
using namespace std;
char s[1000005];
int n,ans,len,a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	n=strlen(s);
	for (int i=0;i<n;i++){
		if (s[i]>='0'&&s[i]<='9')
			a[++len]=(int)(s[i]-'0');
	}
	sort(a+1,a+len+1,cmp);
	for (int i=1;i<=len;i++){
		if (a[1]==0){
			cout<<0;
			return 0;}
		cout<<a[i];
	}
	return 0;
}
