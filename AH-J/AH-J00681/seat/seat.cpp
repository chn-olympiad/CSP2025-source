#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],w,cnt;
bool cmp(int x,int y){
	return x>y;
}
struct student{
	int x,y;
}stu[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	w=a[1];
	for(int i=1;i<=m-m%2;){
		for(int j=1;j<=n;j++){
			stu[++cnt]={i,j};
		}
		i++;
		for(int j=n;j>=1;j--){
			stu[++cnt]={i,j};
		}
		i++;
	}
	for(int i=1;i<=m%2;i++){
		for(int j=1;j<=n;j++){
			stu[++cnt]={m,j};
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==w){
			cout<<stu[i].x<<" "<<stu[i].y<<endl;
			return 0;
		}
	}
}
