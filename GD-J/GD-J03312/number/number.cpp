#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	s=' '+s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		printf("%d",a[i]);
	}
	return 0;
}
