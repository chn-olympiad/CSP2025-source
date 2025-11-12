#include<bits/stdc++.h>
using namespace std;
string a;
char n[1000010];
long long t;
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0' && a[i]<='9'){
			t++;
			n[t]=a[i];
		}
	}
	sort(n+1,n+t+1,cmp);
	for(int i=1;i<=t;i++){
		cout<<n[i];
	}
	return 0;
}
