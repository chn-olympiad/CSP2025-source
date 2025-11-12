#include<bits/stdc++.h>
using namespace std;
int t[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b=1,xiao=0,bj=0;
	getline(cin,a);
	for(int i=0;i<=a.length()-1;i++){
		if('0'<=a[i]&&a[i]<='9'){
			t[b]=a[i]-48;
			b++;
		}
	}
	sort(t+1,t+b);
	for(int i=b-1;i>=1;i--){
		cout<<t[i];
	}
	return 0;
}