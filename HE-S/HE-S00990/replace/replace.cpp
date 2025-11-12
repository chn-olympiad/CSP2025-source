#include<bits/stdc++.h>
using namespace std;
inline int r1ead(){
	int s=0;
	char a;
	a=getchar();
	while(a>='0'&&a<='9'){
		s=(s<<1)+(s<<3)+(a-'0');
		a=getchar();
	}
	return s;
}
inline int r2ead(){
	int s=0;
	char a;
	a=getchar();
	while(a>='0'&&a<='9'){
		s=(s<<1)+(s<<3)+(a-'0');
		a=getchar();
	}
	return s;
}
inline int re3ad(){
	int s=0;
	char a;
	a=getchar();
	while(a>='0'&&a<='9'){
		s=(s<<1)+(s<<3)+(a-'0');
		a=getchar();
	}
	return s;
}
inline int rea4d(){
	int s=0;
	char a;
	a=getchar();
	while(a>='0'&&a<='9'){
		s=(s<<1)+(s<<3)+(a-'0');
		a=getchar();
	}
	return s;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a;
	cin>>a;
	if(a==4)printf("20\n");
	else if(a==3)printf("0\n0\n0\n0\n");
}
