#include<bits/stdc++.h>
#define ll long long
int i;
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int st[1000005],cnt=0;
	cin>>a;
	for(int i=0; i<a.size(); i++){
		if(a[i]>='0'&&a[i]<='9'){
			st[++cnt]=a[i]-'0';
		}
	}
	sort(st+1,st+1+cnt,greater<int>());
	for(int i=1; i<=cnt; i++){
			cout<<st[i];
	}
	return 0;
}
