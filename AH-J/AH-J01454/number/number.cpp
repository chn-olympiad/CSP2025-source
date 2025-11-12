#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
const int N=1e6+5;
int a[N],pos=0,len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++pos]=int(s[i]-'0');
		}
	}
	sort(a+1,a+pos+1,cmp);
	for(int i=1;i<=pos;i++){
		printf("%d",a[i]);
	}
	return 0;
}
