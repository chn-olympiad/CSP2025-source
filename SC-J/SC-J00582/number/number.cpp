#include<bits/stdc++.h>
using namespace std;
long long b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	while(cin>>s){
		if(s>='0'&&s<='9'){
			b[s-'0']+=1;
		}
	}
	for(long long i=9;i>=1;i--){
		if(b[i]>0){
			for(long long j=1;j<=b[i];j++){
				cout<<i;
			}
		}
	}
	for(long long i=1;i<=b[0];i++){
		cout<<0;
	}
}