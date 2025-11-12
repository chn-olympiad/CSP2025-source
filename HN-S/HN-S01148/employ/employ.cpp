#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x){
	x=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
void read(string &str){
	str="";
	char ch=getchar();
	while(ch<'!'||ch>'~')ch=getchar();
	while(ch>='!'&&ch<='~')str+=ch,ch=getchar();
}
void write(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar((char)(x%10+'0'));
}
void write(string str){
	for(int i=0;i<str.size();i++)putchar(str[i]);
}
void write(const char ch[]){
	for(int i=0;i<strlen(ch);i++)putchar(ch[i]);
}
template<typename o,typename...c>
void read(o &a,c&...b){
	read(a);
	read(b...);
}
template<typename o,typename...c>
void write(o a,c...b){
	write(a);
	write(b...);
}
signed main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	return 0;
}

