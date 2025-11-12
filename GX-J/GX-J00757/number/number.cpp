#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b;
	cin>>a;
	for(int i=0;i<int(a.size());i++){
		if(a[i]<='9'&&a[i]>='0')b+=a[i];
	}
	char c[1000001];
	for(int i=0;i<int(b.size());i++){
		c[i]=b[i];
	}
	sort(c,c+b.size());
	for(int i=int(b.size())-1;i>=0;i--){
		cout<<c[i];
	}
	return 0;
}
