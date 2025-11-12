#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int a[N];
int R;
inline bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int t=n*m;
	for(int i=1;i<=t;i++)
		scanf("%d",&a[i]);
	R=a[1];
	sort(a+1,a+t+1,cmp);
	int now=0; 
	for(int i=1;i<=m;i++){
		bool flag=false;
		if(i%2==0){
			for(int j=n;j>=1;j--){
				++now;
				if(a[now]==R){
					printf("%d %d\n",i,j);
					flag=true;
					break;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				++now;
				if(a[now]==R){
					printf("%d %d\n",i,j);
					flag=true;
					break;
				}
			}
		} 
		if(flag)
			break;
	}
	return 0;
}
