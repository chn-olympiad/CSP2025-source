#include<bits/stdc++.h>
using namespace std;
char s;
long long a[20];
bool f;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	while(cin>>s){
		if(int(s)<=57&&int(s)>=48){
			a[int(s-48)]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
} 