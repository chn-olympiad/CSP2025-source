#include<bits/stdc++.h>
using namespace std;
long long b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			int p=a[i]-'0';
			b[p]++;
		}
	}
	for(int i=9;i>=0;i--){
			while(b[i]>0){
			b[i]--;
			cout<<i;
		}
	}
	return 0;
}
