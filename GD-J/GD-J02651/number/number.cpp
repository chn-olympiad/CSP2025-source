#include <iostream>
#include <cstdio>
using namespace std;

char ch;
int num[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>ch){
		if(ch>='0'&&ch<='9')num[ch-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(num[i]--)printf("%d",i);
	}
	return 0;
}
