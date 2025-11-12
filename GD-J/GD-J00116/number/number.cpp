#include<bits/stdc++.h>
using namespace std;
long long a[17];char tmp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>tmp){
		if('0'<=tmp&&tmp<='9')a[tmp-'0']++;
	}
	for(int i=9;i>=0;i--)while(a[i]--)putchar(i+'0');
	return 0;
}
