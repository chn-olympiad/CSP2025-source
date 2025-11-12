#include<bits/stdc++.h>
int n,m;
const int N=1e4+10,M=130;
int a[N][N];
int s[M];
int ss[N];
using namespace std;
int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	int pos=1;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++)s[pos]=read(),pos++;
	}
	int R=s[1];
	sort(s+1,s+pos+1);
	int Pos=1;
	for(int i=pos;i>=1;i--)ss[Pos]=s[i],Pos++;
	Pos=1;
	for(int i=1;i<=n;i++){
		if(i%2==1)for(int j=1;j<=m;j++)a[i][j]=ss[Pos],Pos++;
		if(i%2==0)for(int j=m;j>=1;j--)a[i][j]=ss[Pos],Pos++;
	}
	int ans1,ans2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==R)ans1=i,ans2=j;
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}
