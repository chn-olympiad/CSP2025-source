#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n, m, b[N][N];
int read(){
	int s=0, f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
struct Node{
	int x, id;
}a[N];
bool cmp(Node a, Node b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n=read();
	m=read();
	for(int i=1; i<=n*m; i++) cin>>a[i].x, a[i].id=i;
	sort(a+1, a+n*m+1, cmp);
	for(int j=1; j<=m; j++){
		if(j%2) for(int i=1; i<=n; i++){
			b[i][j]=a[(j-1)*n+i].x;
			if(a[(j-1)*n+i].id==1){
				cout<<j<<' '<<i<<endl;
				return 0;
			}
		}
		else for(int i=n; i>=1; i--){
			b[i][j]=a[(j-1)*n+(n-i+1)].x;
			if(a[(j-1)*n+(n-i+1)].id==1){
				cout<<j<<' '<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
