#include<bits/stdc++.h>
using namespace std;
void print(int x){
	stack<char> s;
	do{
		s.push(x%10+'0');
		x/=10;
	}while(x);
	while(!s.empty()){
		putchar(s.top());
		s.pop();
	}
	putchar(' ');
}
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
bool cmp(int x,int y){
	return x>y;
}
int fs[110];
int Rfs;
int wz[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			fs[i*n+j]=read();
			if(i==1&&j==1)Rfs=fs[i*n+j];
		}
	sort(fs+1,fs+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(i%2)for(int j=1;j<=m;++j) wz[i][j]=++cnt;
		else for(int j=m;j>=1;--j) wz[i][j]=++cnt;
	}
	int Rwz;
	for(int i=1;i<=n*m;++i)
		if(fs[i]==Rfs){
			Rwz=i;
			break;
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(wz[i][j]==Rwz){
				print(i);
				print(j);
				return 0;
			}
}
