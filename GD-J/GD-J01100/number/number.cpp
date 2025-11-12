#include<bits/stdc++.h>
using namespace std;
string s;
int a[500005];
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int cnt=0;
	int temp=s.length();
	int x=0;
	while(cnt<=temp){
		if(s[cnt]>='0'&&s[cnt]<='9') a[x]=s[cnt]-'0',x++;
		cnt++;
	}
	sort(a,a+x,cmp);
	for(int i=0;i<x;i++){
		printf("%d",a[i]);
	}
	return 0;
} 
