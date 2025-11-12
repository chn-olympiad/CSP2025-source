#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int num[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=0,x=s.size();
	for (int i=0;i<x;i++)
		if (s[i]>='0' && s[i]<='9')
			num[n++]=s[i]-'0';
	sort(num,num+n,cmp);
	if (num[0]==0){
		printf("0");
		return 0;
	}
	for (int i=0;i<n;i++) printf("%d",num[i]);
}
