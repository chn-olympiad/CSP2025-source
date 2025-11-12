/*
对于每个员工：
首先先按照对部门的满意度从大到小
如果一个部门已经满员了，
则计算该部门满意度最小员工的满意度是否比该员工小 且 该部门满意度最小员工加入其他部门后亏损的满意度比加入该员工获得的满意度小，
如果是，该员工加入，另外一个员工加入其他部门 
如果否，看下一个满意度的部门是否符合条件 
*/
#include<bits/stdc++.h>
using namespace std;
long long n;
struct aaa{
	long long x,y,z;
	long long xi,yi,zi;
}a[1000005];
priority_queue<pair<long long,pair<long long,long long> >,vector<pair<long long,pair<long long,long long> > >,greater<pair<long long,pair<long long,long long> > > > q[5];
//priority_queue<pair<long long,pair<long long,long long> > > q[5];

long long s[5],ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
		
		s[1]=0;
		s[2]=0;
		s[3]=0;
		ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].xi=1;
			a[i].yi=2;
			a[i].zi=3;
			for(long long k=1;k<=3;k++){
				if(a[i].x<a[i].y){
					swap(a[i].x,a[i].y);
					swap(a[i].xi,a[i].yi);
					
				}
				if(a[i].x<a[i].z){
					swap(a[i].x,a[i].z);
					swap(a[i].xi,a[i].zi);
					
				}
				if(a[i].y<a[i].z){
					swap(a[i].y,a[i].z);
					swap(a[i].yi,a[i].zi);
					
				}
			}
		}
		for(long long i=1;i<=n;i++){
//			if(s[a[i].xi]<n/2){
				s[a[i].xi]++;
				ans+=a[i].x;
				q[a[i].xi].push({a[i].x-a[i].y,{i,1}});
//			}
			/*
			else{
				long long fi=q[a[i].xi].top().first,ff=q[a[i].xi].top().second.first,fx=q[a[i].xi].top().second.second;
				if(fx==1){
					long long sum=a[ff].x-a[ff].y;
					if(sum>a[i].x-a[i].y){
						s[a[i].yi]++;
						ans+=a[i].y;
						q[a[i].yi].push({a[i].y,{i,2}}); 
					}else{
						q[a[i].xi].pop();
						s[a[i].xi]--;
						s[a[ff].yi]++;
						ans-=a[ff].x;
						ans+=a[ff].y;
						q[a[ff].yi].push({a[ff].y,{ff,2}});
						s[a[i].xi]++;
						ans+=a[i].x;
						q[a[i].xi].push({a[i].x,{i,1}});
//						cout<<"11N "<<a[ff].x<<" "<<a[ff].y<<" "<<a[i].x<<" ";
					}
				}else if(fx==2){
					long long sum=a[ff].y-a[ff].z;
					if(sum>a[i].x-a[i].y){
						s[a[i].yi]++;
						ans+=a[i].y;
						q[a[i].yi].push({a[i].y,{i,2}});
					}else{
						q[a[i].xi].pop();
						s[a[i].xi]--;
						s[a[ff].zi]++;
						ans-=a[ff].y;
						ans+=a[ff].z;
						q[a[ff].zi].push({a[ff].z,{ff,3}});
						s[a[i].xi]++;
						ans+=a[i].x;
						q[a[i].xi].push({a[i].x,{i,1}}); 
//						cout<<"111 ";
					}
				}
			}
			*/
		}
		for(long long ss=1;ss<=3;ss++){
			if(s[ss]>n/2){
				while(s[ss]>n/2){
//					long long x=q[ss].top().second.first;
					ans-=q[ss].top().first;
					q[ss].pop();
					s[ss]--;
					
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
4
0 0 3
0 0 4
3 4 5
4 5 6

*/
