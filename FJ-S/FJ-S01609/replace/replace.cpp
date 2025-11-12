#include<iostream>
using namespace std;
int read(){int x=0,f=-1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
