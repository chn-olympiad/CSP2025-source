#include<bits/stdc++.h>
using namespace std;
char c;
int num[1000005],t;
void init(){
	for(int i=0;i<1000005;i++){
		num[i]=0;
	}
	t=0;
	return ;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&c)){
		if((c<'0'||c>'9')&&(c<'a'||c>'z'))	break;
		if(c<='9'&&c>='0'){
			num[t++]=c-'0';
		}
	}
	sort(num,num+t,cmp);
	for(int i=0;i<t;i++){
		printf("%d",num[i]);
	}
	printf("\n");
	return 0;
}
