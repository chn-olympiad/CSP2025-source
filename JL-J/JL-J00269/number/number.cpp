#include<bits/stdc++.h>
using namespace std;
string a;
char b[1000005];
long long len=0,len1;
bool cmp(char a1,char b1){
	return a1>b1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9') b[len1++]=a[i];
	}
	sort(b,b+len1,cmp);
	for(int i=0;i<len1;i++) cout<<b[i];
	return 0;
}
