#include<bits/stdc++.h>
using namespace std;
long long a[1000005],i;
char s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if('0'<=s&&'9'>=s){
			a[a[0]+1]=s-'0';
			a[0]++;
		}
	}
	sort(a+1,a+a[0]+1);
	if(a[a[0]]==0){
		cout<<0;
		return 0;
	}
	for(int i=a[0];i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
