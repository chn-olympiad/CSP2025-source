#include<bits/stdc++.h>
using namespace std;
char a[10000005]; 
int t[1005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&a);
	for(int i=0;i<=strlen(a)-1;i++){
		t[(int)a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=t[i];j>=1;j--){
			cout<<i;
		}
	}
	return 0;
} 
