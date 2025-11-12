#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int cnt;
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
//	freopen("number1.in","r",stdin);
//	freopen("number1.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++cnt]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		printf("%d",a[i]);
	}
	return 0;
}
