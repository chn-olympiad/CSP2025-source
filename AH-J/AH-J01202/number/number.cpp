#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
string a,b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a;
	int l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9')b+=a[i];
	}
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	cout<<b;
	return 0;
}
