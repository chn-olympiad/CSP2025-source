#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y; 
}int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string st;cin>>st;
	int l=st.length();
	int a[l+5]={0},ans=0;
	for(int i=0;i<l;i++)
		if(st[i]>='0'&&st[i]<='9')a[++ans]=st[i]-'0';
	sort(a+1,a+ans+1,cmp);
	for(int i=1;i<=ans;i++)cout<<a[i];
	return 0;
}
