#include<bits/stdc++.h>
using namespace std;
	string a;
	int b[1000001],top=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<=len;i++){
		if('0'<=a[i]&&a[i]<='9'){
			b[top]=a[i]-'0';
			top++;
		}
	}
	sort(b+1,b+top);
	for(int i=top-1;i>=1;i--)cout<<b[i];
	return 0;
}
