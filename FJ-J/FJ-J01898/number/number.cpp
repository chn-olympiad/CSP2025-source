#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	char d;
	int b[1000005],c=0;
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			c++;
			b[c]=a[i];
		}
	}
	sort(b+1,b+c+1);
	for(int i=c;i>=1;i--){
		d=b[i];
		cout<<d;
	}
	return 0;
}
