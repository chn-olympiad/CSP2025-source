#include<bits/stdc++.h>
using namespace std;
string a;
int s[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.size();
	for(int i=0;i<l;i++)if(a[i]>='0'&&a[i]<='9')s[a[i]-'0']++;
	for(int i=9;i>=0;i--)for(int j=1;j<=s[i];j++)printf("%d",i);
	return 0;
}
