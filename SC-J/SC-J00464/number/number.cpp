#include<bits/stdc++.h>
using namespace std;
long long sum[15];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char tmp=getchar();
	while(tmp!='\n'){
		if(!islower(tmp))
			sum[tmp-'0']++;	
		tmp=getchar();
	}
	for(int i=9;i>=0;i--)
		for(int k=1;k<=sum[i];k++)
			cout<<i;
	return 0;
}