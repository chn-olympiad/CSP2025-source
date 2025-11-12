#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],score;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1)score=a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int f=1,x=1,y=1,i=1;i<=n*m;i++){
		if(a[i]==score){
			printf("%d %d\n",y,x);
			return 0;
		}
		if(f==1){
			if(x==n){
				f=-1;
				y++;
			}
			else{
				x++;
			}
		}
		else {
			if(x==1){
				f=1;
				y++;
			}
			else{
				x--;
			}
		}
	}
}
