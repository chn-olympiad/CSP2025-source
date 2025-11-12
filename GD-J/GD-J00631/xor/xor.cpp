#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	char ch=0;
	bool flag=false;
	x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-') flag=true;
		ch=getchar();
	}
	if(flag)
	while(ch>='0'&&ch<='9')
	x=x*10-(ch-'0'),ch=getchar();
	else
	while(ch>='0'&&ch<='9')
	x=x*10+(ch-'0'),ch=getchar();
}
inline void write(int x){
	bool flag=false;
	if(x<0) flag=true;
	if(flag) putchar('-');
	static int sta[40];
	int top=0;
	do{
		sta[top++]=x%10;
		x/=10;
	}while(x);
	if(flag)
	while(top) putchar('0'-sta[--top]);
	else
	while(top) putchar('0'+sta[--top]);
}
int n,k;
int a[5*100005];
int b[1005][1005],cnt,sum;
struct data{
	int begin,end,lon;
}c[5*100005];
bool cmp(data x,data y){
	if(x.lon<y.lon) return true;
	else if(x.lon==y.lon&&x.begin<y.begin) return true;
	else return false;
}
int flag[5*100005];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=n;i++){
		read(a[i]);
		for(int j=1;j<i;j++){
			b[j][i]=b[j][i-1]^a[i];
			//write(b[j][i]),putchar(' ');
			if(b[j][i]==k) cnt++,c[cnt].begin=j,c[cnt].end=i,c[cnt].lon=i-j+1;
		}
		b[i][i]=a[i];
		//write(b[i][i]),putchar('\n');
		if(b[i][i]==k) cnt++,c[cnt].begin=i,c[cnt].end=i,c[cnt].lon=1; 
	}
	sort(c+1,c+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		bool pd=false;
		for(int j=c[i].begin;j<=c[i].end;j++)
		if(flag[j]==1){
			pd=true;
			break;
		}
		if(pd==false) {
			sum++;
			for(int j=c[i].begin;j<=c[i].end;j++)
			flag[j]=1;
		}
	}
	write(sum);
	return 0;
}
//GD-J00631
//CCF is bad
