#include<bits/stdc++.h>
using namespace std;
char a[1000010]; 
int b[100],c,cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	c=strlen(a);
	for(int i=0;i<c;i++){
		int w=a[i]-'0';
		if(w>=0&&w<=9) b[w]++,cnt++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++) printf("%d",i);
	}
	return 0;
}
