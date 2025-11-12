#include<bits/stdc++.h>
using namespace std;
string m;
int a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>m;
	int c=size(m);
	for(int i=0;i<c;i++){
		if(m[i]<='9'&&m[i]>='0'){
			a[m[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
}