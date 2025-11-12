#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,id=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		id++;
		scanf("%d",&a[id]);
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,k=1;
	for(int iid=1;iid<=n*m;iid++){
		
		if(a[iid]==t){
			printf("%d %d",x,y);
			return 0;
		}
		y+=k;
		if(y>n){
			k=-k;
			x++;
			y--;
		}
		else if(y<1){
			k=-k;
			x++;
			y++;
		}
		
	}
	return 0;
}
