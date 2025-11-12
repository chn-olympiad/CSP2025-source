#include<bits/stdc++.h>
using namespace std;
int a[20][20],b[400];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,c=0,r=0,s;
	scanf("%d %d",&n,&m);
	s=n*m;
	for(int i=1;i<=s;i++){
		scanf("%d",&b[i]);
	}
	t=b[1];
	sort(b+1,b+1+s,cmp);
	b[0]=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				b[0]++;
				a[i][j]=b[b[0]];
				if(a[i][j]==t){
					c=j;
					r=i;
					break;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				b[0]++;
				a[i][j]=b[b[0]];
				if(a[i][j]==t){
					c=j;
					r=i;
					break;
				}
			}
		}
		if(c!=0&&r!=0){
			break;
		}
	}
	printf("%d %d",c,r);
	return 0;
}
