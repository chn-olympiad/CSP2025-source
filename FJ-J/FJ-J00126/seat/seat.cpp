#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100;
int n,m,cnt;
struct node{
	int v,id;
}a[N];
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48),ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x<10){putchar(x+48);}
	else{write(x/10);putchar(x%10+48);}
	return;
}
bool cmp(node tx,node ty){
	return tx.v>ty.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)a[i].v=read(),a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt].id==1){
					write(i);
					putchar(' ');
					write(j);
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt].id==1){
					write(i);
					putchar(' ');
					write(j);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
