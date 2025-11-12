#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;

inline int read(){
	int x=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch^'0';
		ch=getchar();
	}
	return x*f;
}

inline void write(int x){
	if(x<0){
		putchar('-');
		write(-x); 
		return;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

string s;
int a[10];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<strlen(s.c_str());++i) ++a[s[i]-'0'];
	for(int i=9;i>=0;--i){
		while(a[i]--) write(i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}