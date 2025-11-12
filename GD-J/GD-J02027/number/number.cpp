#include<bits/stdc++.h>
using namespace std;
string a;
long long b[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	long long l=a.length(),chang=0;
	for(long long i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[chang]=a[i]-'0';
			chang++;
		}
	}
	sort(b,b+chang,greater<int>());
	for(long long i=0;i<chang;i++){
		cout<<b[i];
	}
	return 0;
}
