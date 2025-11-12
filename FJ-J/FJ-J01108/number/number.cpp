#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length(),j=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			j++;
			a[j]=s[i]-'0';
		}
	}
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j;i++){
		printf("%d",a[i]);
	}
	return 0;
}
