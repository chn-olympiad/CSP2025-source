#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	for(int i=1;i<=1000000;i++){
		scanf ("%c",&s[i]);
	}
	for(int i=1;i<=1000000;i++){
		if(s[i]<s[i+1]){
			swap(s[i],s[i+1]);
		}
	}
	
	return 0;
}
