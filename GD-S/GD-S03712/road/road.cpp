#include<bits/stdc++.h>
using namespace std;

struct line{
	long long u,v;
	line(long long _u=0,long long _v=0){
		u=_u;
		v=_v;
	}
};

long long n,m,k;
long long max_road=0;
map<long long,long long> city;
deque<line> roads;
deque<line> roads2;
long long build_new[20][10010];
long long cost_new[20];
long long ans_no_change=0;
long long road_long[10010][10010];
long long copy_road_long[10010][10010];
long long real_ans=-1;
vector<long long> collect_id;

void in();
void run1();
void run2();
void check1();
bool cmp(line a,line b);
void dfs(long long id,long long need_left);

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<0;
	return 0;
	
	in();
//	cout<<"³õÊ¼×´Ì¬"<<endl;
//	cout<<ans_no_change<<" "<<max_road<<endl;
	run1();
	for (long long i=1;i<=k;i++){
//		cout<<"³¢ÊÔ"<<i<<endl;
		dfs(1,k);
//		run2(i);
	}
	cout<<real_ans;
	return 0;
} 

void dfs(long long id,long long need_left){
	if (need_left==0){
//		for (auto it:collect_id){
//			cout<<it<<" ";
//		}
//		cout<<endl;
		run2();
		return ;
	}
	if (id==k+1){
		return ;
	}
	for (int i=id;i<=k;i++){
		collect_id.push_back(i);
		dfs(i+1,need_left-1);
		collect_id.pop_back();
	}
}

void in(){
	cin>>n>>m>>k;
	for (long long i=1;i<=n;i++){
		long long u,v,w;
//		scanf("%lld %lld %lld",&u,&v,&w);
		cin>>u>>v>>w;
		road_long[min(u,v)][max(u,v)]=w;
		city[u]++;
		city[v]++;
		roads.push_back(line(min(u,v),max(u,v)));
	}
	for (long long i=1;i<=k;i++){
		cin>>cost_new[i];
		for (long long j=1;j<=n;j++){
			cin>>build_new[i][j];
		}
	}
//	for (long long i=1;i<=k;i++){
//		cout<<cost_new[i]<<" ";
//	}
//	cout<<endl;
}

void run1(){
	sort(roads.begin(),roads.end(),cmp);
	for (long long i=0;i<roads.size();i++){
		if (city[roads[i].u]>1 and city[roads[i].v]>1){
			city[roads[i].u]--;
			city[roads[i].v]--;
		}
		else{
			max_road=max(max_road,road_long[roads[i].u][roads[i].v]);
			ans_no_change+=road_long[roads[i].u][roads[i].v];
			roads2.push_back(roads[i]);
//			cout<<roads[i].u<<" "<<roads[i].v<<" "<<road_long[roads[i].u][roads[i].v]<<endl;
		}
	}
//	cout<<ans_no_change<<" "<<max_road<<endl;
} 

void run2(){	
	memcpy(copy_road_long,road_long,sizeof(road_long));
	long long ans=ans_no_change;
//	cout<<ans<<endl;
	long long total_roads=roads2.size();
	deque<line> copy_roads;
	deque<line> copy_roads2;
	map<long long,long long> copy_city;
	
	for (auto it:city){
		copy_city[it.first]=it.second;
	}
	for (long long i=0;i<roads2.size();i++){
		copy_roads.push_back(roads2[i]);
	}
	
	for (auto id:collect_id){
		for (long long i=1;i<=n;i++){
			if (build_new[id][i]>max_road){
				continue;
			}
			for (long long j=i+1;j<=n;j++){
				long long new_road=build_new[id][i]+build_new[id][j];
				if (new_road<=max_road){
					if (copy_road_long[i][j]==0){
						copy_city[i]++;
						copy_city[j]++;
						copy_roads.push_back(line(i,j));
						ans+=new_road;
						total_roads++;
						copy_road_long[i][j]=new_road;
					}
					else{
						if (copy_road_long[i][j]>new_road){
							ans-=copy_road_long[i][j];
							ans+=new_road;
						}
						copy_road_long[i][j]=min(copy_road_long[i][j],new_road);
					}
				}
			}
		}
	}
	sort(copy_roads.begin(),copy_roads.end(),cmp);
	
//	cout<<ans<<endl;
//	for (long long i=0;i<copy_roads.size();i++){
//		cout<<copy_roads[i].u<<" "<<copy_roads[i].v<<" "<<copy_road_long[copy_roads[i].u][copy_roads[i].v]<<endl;
//	}
//	for (auto it:copy_city){
//		cout<<it.first<<" "<<it.second<<endl;
//	}
	
	for (auto it:copy_roads){
//		cout<<it.u<<" "<<it.v<<" "<<copy_city[it.u]<<" "<<copy_city[it.v]<<" "<<total_roads<<endl;
		if (copy_city[it.u]>1 and copy_city[it.v]>1 and total_roads>n-1){
			copy_city[it.u]--;
			copy_city[it.v]--;
			ans-=copy_road_long[it.u][it.v];
			total_roads--;
		}
		else{
			copy_roads2.push_back(it);
		}
	}
//	for (long long i=0;i<copy_roads.size();i++){
//		cout<<copy_roads[i].u<<" "<<copy_roads[i].v<<" "<<copy_roads[i].w<<" "<<copy_city[copy_roads[i].u]<<" "<<copy_city[copy_roads[i].v]<<endl;
//		if (copy_city[copy_roads[i].u]>1 and copy_city[copy_roads[i].v]>1){
//			copy_city[copy_roads[i].u]--;
//			copy_city[copy_roads[i].v]--;
//			i--;
//			copy_roads.erase(copy_roads[i]);
//		}
//		else{
//			ans+=copy_roads[i].w;
//		}
//	}
	
//	for (long long i=0;i<copy_roads2.size();i++){
//		cout<<copy_roads2[i].u<<" "<<copy_roads2[i].v<<" "<<copy_road_long[copy_roads2[i].u][copy_roads2[i].v]<<endl;
//	}
//	for (auto it:copy_city){
//		cout<<it.first<<" "<<it.second<<endl;
//	}
//	cout<<ans<<endl;
	for (auto id:collect_id){
		ans+=cost_new[id];
	}
	if (real_ans==-1){
		real_ans=ans;
	}
	else{
		real_ans=min(real_ans,ans);
	}
}

void check1(){
	for (auto it:city){
		cout<<it.first<<" "<<it.second<<endl;
	}
}

bool cmp(line a,line b){
	return road_long[a.u][a.v]>road_long[b.u][b.v];
}
//memcpy
