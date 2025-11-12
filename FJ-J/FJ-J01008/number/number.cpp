#include<iostream>
using namespace std;

int f[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char ch;
	while((ch=getchar())&&ch!='\n'&&ch!='\r'&&ch!=EOF){
		if(ch>='0'&&ch<='9')f[ch-'0']++;
	}
	for(int i=9;i+1;i--){
		while(f[i]--)cout<<i;
	}
}
