#include<bits/stdc++.h>
using namespace std;
struct student{
	int ta,tb,tc,id;
	bool used=false;
}stu[100005],stu1[100005];
bool cmp(student a,student b){
	return a.tb>b.tb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&stu[i].ta,&stu[i].tb,&stu[i].tc);
			stu[i].id=i;
			stu1[i]=stu[i];
		}
		sort(stu+1,stu+n+1,cmp);
		int i;
		for(i=1;i<=n/2;i++){
			ans+=stu[i].tb;
			stu[i].used=true;
		}
//		stu1=stu;
		
		printf("%d\n",ans);
	}
	
	return 0;
}

