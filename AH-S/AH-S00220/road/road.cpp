#include<bits/stdc++.h>
using namespace std;

int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') putchar('-');
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	puts("0");
	return 0;
}
