#include<bits/stdc++.h>
using namespace std;
int n,m,res,ans;
struct student{
	int num,gra;
}a[105];
bool cmp(student A,student B){
	return A.gra>B.gra;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].gra);
		a[i].num=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			res=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				ans++;
				if(ans==res){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				ans++;
				if(ans==res){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
