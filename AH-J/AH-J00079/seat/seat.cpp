#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int t=m*n;
	int maxnsum=1;
	for(int i=1;i<=t;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1]) maxnsum++;
	}
	bool f=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			maxnsum--;
			if(maxnsum<=0){
				cout<<i<<' '<<j;
				f=1;
				break;
			}
		}
		if(f==1){
			break;
		}
		i++;
		for(int j=n;j>=1;j--){
			maxnsum--;
			if(maxnsum<=0){
				cout<<i<<' '<<j;
				f=1;
				break;
			}
		}
		if(f==1){
			break;
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
