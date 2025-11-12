#include<bits/stdc++.h>
using namespace std;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s=0;
	string a;
	cin>>a;
	int j=a.size();
	for(int i=0;i<j;i++){
		if(a[i]<='9' && a[i]>='0'){
			b[s++]=a[i]-48;
		}
	}
	sort(b,b+s);
	for(int i=s-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
