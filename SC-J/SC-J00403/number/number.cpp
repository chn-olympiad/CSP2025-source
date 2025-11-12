#include<bits/stdc++.h>
using namespace std;
char x[1000001];
int a,b[11];
//bool cmp(int x,int y){
//	if(x>y)
//		return 1;
//	return 0;
//}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	gets(x);
	for(int i=0;x[i]!=0;i++){
		if(x[i]<='9'&&x[i]>='0'){
			a=x[i]-'0';
			b[a]+=1;		}
	}
//	sort(a+1,a+n+1,cmp);
	
	for(int i=9;i>=0;i--){
		a=b[i];
		for(int j=1;j<=a;j++)
			printf("%d",i);	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}