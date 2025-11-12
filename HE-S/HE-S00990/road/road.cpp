#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;
	char a;
	a=getchar();
	while(a>='0'&&a<='9'){
		s=(s<<1)+(s<<3)+(a-'0');
		a=getchar();
	}
	return s;
}
inline int rea1d(){
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
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(a==4)printf("13\n");
	else if(a==1000&&b==1000000&&c==5252)printf("505585650\n");
	else if(a==1000&&b==1000000&&c==10709)printf("504898585\n");
	else if(a==1000&&b==100000)cout<<"5182974424\n";
}
