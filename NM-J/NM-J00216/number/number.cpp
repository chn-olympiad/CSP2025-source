#include <bits/stdc++.h>
using namespace std;

char a[100000000000000000005];
int s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=s;i++){
		if (s[a]<=9){
			cout<<s[a];
			break;
		}
		else cout<<a;
		break;
	}
	return 0;
} 
