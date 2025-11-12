#include<bits/stdc++.h>
using namespace std;
string a;
long long b[1000005],k=0;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in ","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	int s=a.size();
	for(int i=0;i<s;i++){
		b[i]=-10;
		if(a[i]>='0' &&a[i]<='9'){
			b[i]=a[i]-48;
		}
		if(a[i]=='0'){
			k++;
		}
	}
	sort(b,b+s,cmp);
	for(int i=0;i<s;i++){
		if(b[i]>0){
			cout<<b[i];
		}
	}
	for(int i=1;i<=k;i++){
		cout<<0;
	}
	return 0;
}
