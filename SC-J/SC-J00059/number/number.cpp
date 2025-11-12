#include<bits/stdc++.h>
using namespace std;
int ans,s=1,b[100010];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(48<=a[i]&&a[i]<=57){
			b[s++]=a[i]-48;
		}
	}
	sort(b+1,b+s+1);
	for(int i=s;i>=2;i--){
		cout<<b[i];
	}
	return 0;
} 