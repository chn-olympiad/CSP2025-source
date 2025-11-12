#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c,d[101];
	scanf("%d%d",&a,&b);
	c=a*b;
	for(int i=1;i<=c;i++){
		scanf("%d",d[i]);
	}
	int r=d[1];
	for(int i=2;i<=c;i++){
		int e;
		if(d[i-1]<=d[i]){
			c=d[i-1];
			d[i-1]=d[i];
			d[i]=c;
		}
	}
	int f=0;
	for(int i=2;i<=c;i++){
		f++;
		if(d[i]==r){
			break;
		}
	}
	int h=f/b,g;
	char q=' ';
	if(h%2==0){
		g=a-f%2;
	}
	else{
		g=f%2;
	}
	printf("%d%c%d",h,q,g);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
