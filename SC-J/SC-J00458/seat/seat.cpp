#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;char c;int f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x*=f;
}
inline void write(int x){
	if(x==0) return ;
	if(x<0) putchar('-'),x=-x;
	write(x/10);
	putchar(x%10+48);
	return ;
}
int a[100005];
int n,m;
int C;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n*m;i++){
		read(a[i]);
	}
	C=a[1];
	sort(a+1,a+n*m+1);
	int cnt=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[cnt--]==C){
					cout<<i<<' '<<j;
					exit(0);
				}
//				cout<<cnt;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[cnt--]==C){
					cout<<i<<' '<<j;
					exit(0);
				}
//				cout<<cnt;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

