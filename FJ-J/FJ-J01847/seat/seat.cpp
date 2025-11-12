#include<bits/stdc++.h>
using namespace std;
int mp[19][19];
struct node{
	int grade,id;
}a[109];
bool cmp(node p,node q){
	return p.grade>q.grade;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,r,c;
	cin>>n>>m;
	for(i=1;i<=m*n;i++){
		scanf("%d",&a[i].grade);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(i%2){
				mp[i][j]=a[(i-1)*n+j].grade;
				if(a[(i-1)*n+j].id==1) r=i,c=j;
			}
			else{
				mp[i][n-j+1]=a[(i-1)*n+j].grade;
				if(a[(i-1)*n+j].id==1) r=i,c=n-j+1;
			}
		}
	}
	printf("%d %d",r,c);
	return 0;
}
