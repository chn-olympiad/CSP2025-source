#include<bits/stdc++.h>
using namespace std;
char a[1000000],c[15]={'0','1','2','3','4','5','6','7','8','9'};
long long b[15],m,x;
int main(){
	cin>>a;
	m=strlen(a);
	for(int i=0;i<m;i++){
		for(int j=0;j<=9;j++){
			if(c[j]==a[i]){
				b[j]++;
			}
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			cout<<i;
		}
	}
	return 0;
}