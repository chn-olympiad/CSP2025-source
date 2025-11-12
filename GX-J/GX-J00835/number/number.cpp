#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b[1000000]={0},c=0;
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[c]=a[i]-48;
			c++;
		}
	}
	sort(b+0,b+c);
	for(int i=c-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
