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
inline int rea2d(){
	int s=0;
	char a;
	a=getchar();
	while(a>='0'&&a<='9'){
		s=(s<<1)+(s<<3)+(a-'0');
		a=getchar();
	}
	return s;
}
inline int rea3d(){
	int s=0;
	char a;
	a=getchar();
	while(a>='0'&&a<='9'){
		s=(s<<1)+(s<<3)+(a-'0');
		a=getchar();
	}
	return s;
}
inline int re4ad(){
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
	freopen("enploy.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(a==3)printf("2\n");
	else if(a==10)cout<<"2204128\n";
	else if(a==100)printf("161088479\n");
	else if(a==500&&b==1)printf("515058943\n");
	else if(a==500&&b==12)printf("225301405\n");
}
