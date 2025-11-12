#include<bits/stdc++.h>
using namespace std;
int read(){
	int x;bool f=0;char ch;
	while((ch=getchar())<'0' || ch>'9')if(ch=='-')f=1;
	x=ch-'0';
	while((ch=getchar())>='0' && ch<='9')x=(x<<3)+(x<<1)+ch-'0';
	return f?-x:x;
}
int n,m;
int a[110];
bool cmp(int b,int c){return b>c;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++){
		a[i]=read();
	}
	int cj=a[1];
	int wz;
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=1;i<=n*m;i++)if(a[i]==cj){wz=i;break;}
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				wz--;
				if(wz==0){
					printf("%d %d",i,j);
					return 0;
				}				
			}
		}else{
			for(int j=n;j>=1;j--){
				wz--;
				if(wz==0){
					printf("%d %d",i,j);
					return 0;
				}				
			}
		}
	}
	return 0;
}

