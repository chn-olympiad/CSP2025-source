#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a1,a2,a3;
long long ans=0;
int query=0;
struct node{
	int c1,c2,c3;
	int id1,id2,id3;
	int k=0;
}stu[100005]; 
int jishu[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1,&a2,&a3);
			stu[i].c1=max(max(a1,a2),a3);
			stu[i].c3=min(min(a1,a2),a3);
			query=a1+a2+a3;
			stu[i].c2=query-stu[i].c1-stu[i].c3;
			stu[i].k=0;
			if(a1>=a2&&a1>=a3){
				stu[i].id1=1;
				if(a2>=a3){
					stu[i].id2=2;
					stu[i].id3=3;
				}
				else{
					stu[i].id2=3;
					stu[i].id3=2;
				}
			}
			else if(a2>=a1&&a2>=a3){
				stu[i].id1=2;
				if(a1>=a3){
					stu[i].id2=1;
					stu[i].id3=3;
				}
				else{
					stu[i].id2=3;
					stu[i].id3=1;
				}
			}
			else{
				stu[i].id1=3;
				if(a1>=a2){
					stu[i].id2=1;
					stu[i].id3=2;
				}
				else{
					stu[i].id2=2;
					stu[i].id3=1;
				}
			}
		}
		
		ans=0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q[3];
		jishu[1]=0;
		jishu[2]=0;
		jishu[3]=0;
		for(int i=1;i<=n;i++){
			jishu[stu[i].id1]++;
			
			if(jishu[stu[i].id1]>(n/2)){
				int f1=q[stu[i].id1-1].top().first,f2=q[stu[i].id1-1].top().second;
				if(f1+stu[i].c1>=stu[i].c2){
					q[stu[i].id1-1].pop();
					q[stu[i].id1-1].push({stu[i].c1-stu[i].c2,i});
					jishu[stu[i].id1]--;
					jishu[stu[f2].id2]++;
					q[stu[f2].id2-1].push({stu[f2].c2-stu[f2].c3,f2});
					ans+=stu[f2].c2-stu[f2].c1+stu[i].c1;
				}
				else{
					q[stu[i].id2-1].push({stu[i].c2-stu[i].c3,i});
					jishu[stu[i].id2]++;
					jishu[stu[i].id1]--;
					ans+=stu[i].c2;	
				}
			}
			
			else{
				q[stu[i].id1-1].push({stu[i].c1-stu[i].c2,i});
				ans+=stu[i].c1;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
