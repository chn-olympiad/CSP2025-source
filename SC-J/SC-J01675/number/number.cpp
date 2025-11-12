#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char a[N];
int sum[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	int n=strlen(a+1);
	for(int i=1;i<=n;i++){
		if(isdigit(a[i])) sum[a[i]-'0']++;
	} 
	for(int i=9;i>=0;i--){
		if(sum[i]){
			for(int j=1;j<=sum[i];j++) cout<<i;
		}
	}
	return 0;
}
