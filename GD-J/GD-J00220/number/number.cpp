#include<bits/stdc++.h>
using namespace std;char a[1145141];short b[1145141];
bool ss(short x,short y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>a;int l=strlen(a)-1;
	int bl=0;
	for(int i=0;i<=l;i++){
		if(a[i]<='9'&&a[i]>='0'){
			bl++;
			b[bl]=a[i]-'0';
		}
	}
	sort(b+1,b+bl+1,ss);
	for(int i=1;i<=bl;i++){
		cout<<b[i];
	}
	return 0;
}
