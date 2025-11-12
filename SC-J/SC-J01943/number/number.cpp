#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length(),cnt=1;
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[cnt++]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt,cmp);
	for(int i=1;i<cnt;i++){
		printf("%d",a[i]);
	}
	return 0;
}