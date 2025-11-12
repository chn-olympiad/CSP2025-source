#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int n,m,num[115];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		scanf("%lld",&num[i]);
	}int f=num[1];
	sort(num+1,num+n*m+1,cmp);
	int sx=1,sy=1,i=1;
	while(i<=n*m&&sx<=n&&sy<=m){
		a[sx][sy]=num[i];
		if(a[sx][sy]==f){
			cout<<sy<<" "<<sx;
			return 0;
		}
		if((sx%n==0&&sy%2==1)||(sx==1&&sy%2==0)){
			sy++; 
			i++; 
			continue;
		}
		if(sy%2==1){
			sx++;
		}else{
			sx--;
		}
		i++;
		
	}
	
	
	return 0;
}


