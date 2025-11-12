#include<bits/stdc++.h>
using namespace std;
int a[1000006];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
  freopen("number3.in","r",stdin);
  freopen("number3.out","w",stdout);
	cin>>s;
	int len=s.size(),n=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(i==1&&a[1]==0) {cout<<0;break;}
		cout<<a[i];
	}
	return 0;
}
