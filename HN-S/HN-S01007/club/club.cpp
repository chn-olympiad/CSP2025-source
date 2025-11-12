#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c,cnt1,cnt2,cnt3,maxi,ans;
struct node{
	int v1,v2,v3,now;
	bool operator > (const node &x)const{
		if(now==1){
			if(v1!=x.v1)return v1>x.v1;
			else return max(v2,v3)<max(x.v2,x.v3);
		}
		if(now==2){
			if(v2!=x.v2)return v2>x.v2;
			else return max(v1,v3)<max(x.v3,x.v1);
		}
		if(now==3){
			if(v3!=x.v3)return v3>x.v3;
			else return max(v2,v1)<max(x.v2,x.v1);
		}
	}
}stu[200005];
priority_queue<node,vector<node>,greater<node> >q1,q2,q3;
inline void init(){
	maxi=n/2;cnt1=cnt2=cnt3=0;
	for(int i=1;i<=n;i++)stu[i].now=stu[i].v1=stu[i].v2=stu[i].v3=0;
	while(!q1.empty())q1.pop();
	while(!q2.empty())q2.pop();
	while(!q3.empty())q3.pop();
}
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&stu[i].v1,&stu[i].v2,&stu[i].v3);
			//stu[i].now=1;
			//q1.push(stu[i]);
		}
		/*for(int i=1;i<=n;i++){
			printf("%d",q1.top().id);
			q1.pop();
		}*/
		for(int i=1;i<=n;i++){
			if(stu[i].v1>stu[i].v2&&stu[i].v1>stu[i].v3){
				if(cnt1<maxi){stu[i].now=1;q1.push(stu[i]);ans+=stu[i].v1;cnt1++;}	//有空位 
				else{
					node k1=q1.top();
					if(stu[i].v1>k1.v1){
						q1.pop();
						ans-=k1.v1;
						n++;
						stu[n].v1=-1000;
						stu[n].v2=k1.v2;
						stu[n].v3=k1.v3;
						stu[i].now=1;q1.push(stu[i]);ans+=stu[i].v1;
					}
					else if(k1.v1-stu[i].v1<=k1.v2||k1.v1-stu[i].v1<=k1.v3){
						q1.pop();
						ans-=k1.v1;
						n++;
						stu[n].v1=-1000;
						stu[n].v2=k1.v2;
						stu[n].v3=k1.v3;
						stu[i].now=1;q1.push(stu[i]);ans+=stu[i].v1;
					}
				}
			}
			if(stu[i].v2>stu[i].v1&&stu[i].v2>stu[i].v3){
				if(cnt2<maxi){stu[i].now=2;q2.push(stu[i]);ans+=stu[i].v2;cnt2++;}	//有空位 
				else{
					node k2=q2.top();
					if(stu[i].v2>k2.v2){
						q2.pop();
						ans-=k2.v2;
						n++;
						stu[n].v1=k2.v1;
						stu[n].v2=-1000;
						stu[n].v3=k2.v3;
						stu[i].now=2;q2.push(stu[i]);ans+=stu[i].v2;
					}
					else if(k2.v2-stu[i].v2<=k2.v1||k2.v2-stu[i].v2<=k2.v3){
						q2.pop();
						ans-=k2.v2;
						n++;
						stu[n].v1=k2.v1;
						stu[n].v2=-1000;
						stu[n].v3=k2.v3;
						stu[i].now=2;q2.push(stu[i]);ans+=stu[i].v2;
					}
				}
			}
			if(stu[i].v3>stu[i].v2&&stu[i].v3>stu[i].v1){
				if(cnt3<maxi){stu[i].now=3;q3.push(stu[i]);ans+=stu[i].v3;cnt3++;}	//有空位 
				else{
					node k3=q3.top();
					if(stu[i].v3>k3.v3){
						q3.pop();
						ans-=k3.v3;
						n++;
						stu[n].v1=k3.v1;
						stu[n].v2=k3.v2;
						stu[n].v3=-1000;
						stu[i].now=3;q3.push(stu[i]);ans+=stu[i].v3;
					}
					else if(k3.v3-stu[i].v3<=k3.v2||k3.v3-stu[i].v3<=k3.v1){
						q3.pop();
						ans-=k3.v3;
						n++;
						stu[n].v1=k3.v1;
						stu[n].v2=k3.v2;
						stu[n].v3=-1000;
						stu[i].now=3;q3.push(stu[i]);ans+=stu[i].v3;
					}
				}
			}
		}
		printf("%d\n",ans);
		ans=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
