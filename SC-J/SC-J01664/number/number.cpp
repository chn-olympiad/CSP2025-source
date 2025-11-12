#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int cnt=0,a[N];
bool cup(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++cnt]=(int)(s[i]-'0');
		}
	}
	sort(a+1,a+cnt+1,cup);
	for(int i=1;i<=cnt;i++){
		printf("%d",a[i]);
	}
	return 0;
}