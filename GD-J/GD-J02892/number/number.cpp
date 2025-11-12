#include<bits/stdc++.h>
using namespace std;
int a[11];
bool flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char ch=getchar();
	while(ch>='0'&&ch<='9'||ch>='a'&&ch<='z'){
		if(ch>='0'&&ch<='9') a[ch-'0']++;
		ch=getchar();
	}
	for(int i=9;i>0;i--){
		while(a[i]--){
			printf("%d",i);
			flag=1;
		}
	}
	if(!flag){
		cout<<0;
	}
	else{
		while(a[0]--){
			printf("%d",0);
		}
	}
	return 0;
}
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
//թƭ ! 

