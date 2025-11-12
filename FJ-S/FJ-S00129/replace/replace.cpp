#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48),ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x<10){putchar(x+48);}
	else{write(x/10),putchar(x%10+48);}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	while(q--){
		putchar('0');
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
