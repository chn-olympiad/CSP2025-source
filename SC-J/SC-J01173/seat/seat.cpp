#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],now=0;
bool cmp(int a,int b){
	return a>b;
}
void shuchu(int x){
	int yu=x%n;
	int lie=x/n;
	if(yu!=0){
		lie++;
	} 
	printf("%d ",lie); 
	int hang=yu;
	if(lie%2==0){
		hang=n-hang+1;
	}
	if(hang==0){
		hang=n;
	}
	printf("%d",hang);
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1) now=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n* m;i++){
		if(a[i]==now){
			shuchu(i);
			break;
		}
	}
	return 0;
} 