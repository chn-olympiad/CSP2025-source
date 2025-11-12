#include<bits/stdc++.h>
#include<string>
using namespace std;
int c[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i = 0; a[i] != '\0';i++){
		if(a[i] >= '0' && a[i] <= '9'){
			c[int(a[i]-'0')]++;
		}
	}
	int i = 9;
	while(i>=0){
		while(c[i]--){
			printf("%d",i);
		}
		i--;
	}
	return 0;
}
