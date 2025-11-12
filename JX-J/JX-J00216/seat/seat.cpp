#include<iostream>
#include<algorithm>
using namespace std;
int cmp(int a,int b){
	return a > b;
} //sort cmp

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	int a[101] = {0};
	int cnt = 1;
//        weight height
	int seat[11][11] = {0};
	scanf("%d %d",&n,&m);
	int x = n * m;
	for(int i=1;i<=x;i++){
		scanf("%d",&a[i]);
	}
	R = a[1];
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=m;i++){
		if(i % 2 == 1){
			for(int j=1;j<=n;j++){
				seat[j][i] = a[cnt];
				if(a[cnt] == R){
					printf("%d %d",i,j);
					return 0;
				}
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				seat[j][i] = a[cnt];
				if(a[cnt] == R){
					printf("%d %d",i,j);
					return 0;
				}
				cnt++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}