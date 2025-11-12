#include<bits/stdc++.h>
using namespace std;
struct st{
	int scr,x,y;
};
bool cmp(st a,st b){
	return a.scr>b.scr;
}
signed main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,i,t=1,sy=1,pos;
	st stu[101];
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		scanf("%d",&stu[i].scr);
	pos=stu[1].scr;
	sort(stu+1,stu+n*m+1,cmp);
	while(t<=m*n){
		for(i=1;i<=n;i++){
			stu[t].x=i,stu[t].y=sy;
			t++;
		}
		sy++;
		for(i=n;i>=1;i--){
			stu[t].x=i,stu[t].y=sy;
			t++;
		}
		sy++,i++;
	}
	for(i=1;i<=n*m;i++)
		if(stu[i].scr==pos){
			printf("%d %d",stu[i].y,stu[i].x);
			break;
		}
	return 0;
}