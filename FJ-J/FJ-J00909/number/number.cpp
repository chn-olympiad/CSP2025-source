#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	char c[1000005];
	cin>>c;
	long long a[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	int i=0;
	while(true){
		if(c[i]>='0' && c[i]<='9'){
			a[c[i]-'0']++;
		}
		if(c[i]=='\n') break;
		i++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--) cout<<i;
	}
	return 0;
} 
