#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[20][20],a[210],cheng,zhi;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	cheng=a[1];
	sort(a+1,a+1+n*m,cmp);
	zhi=0;
	int flag=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
		for(int j=1;j<=m;j++){
			++zhi;
			mp[j][i]=a[zhi];
			if(a[zhi]==cheng){
				cout<<i<<" "<<j;
				flag=1;
				break;
			}
		}
	    }else{
	      for(int j=m;j>=1;j--){
			++zhi;
			mp[j][i]=a[zhi];
			if(a[zhi]==cheng){
				cout<<i<<" "<<j;
				flag=1;
				break;
			}
		}
		}
		if(flag==1) break;
	}
	return 0;
}
