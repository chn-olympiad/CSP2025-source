#include<bits/stdc++.h>
using namespace std;
string b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a[10]={0};
	cin>>b;
	for(int i=0;i<b.size();i++){

		if(b[i]>='0'&&b[i]<='9'){
			a[b[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			while(a[i]--){
				cout<<i;
			}
		}
	}
}
