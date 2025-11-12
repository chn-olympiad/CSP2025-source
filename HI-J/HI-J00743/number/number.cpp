#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			int f=s[i]-'0';
			cnt++;
			a[cnt]=f;
		}
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=cnt;i++){
		printf("%d",a[i]);
	}
	return 0;
}
