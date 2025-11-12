#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
long long b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	//for(int i=0;i<10;i++)b[i]=0;
	for(char i:a){
		if(i>='0' && i<='9'){
			b[i-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]--)printf("%d",i);
	}
	return 0;
}
