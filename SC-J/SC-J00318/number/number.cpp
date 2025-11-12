#include<bits/stdc++.h>
using namespace std;
long long a[10]; 
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c) if('0'<=c&&c<='9') a[c-'0']++;
	for(int i=9;i>=0;i--) while(a[i]) printf("%d",i),a[i]--;
	return 0;
}
