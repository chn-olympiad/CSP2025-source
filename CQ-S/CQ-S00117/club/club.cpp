#include<bits/stdc++.h> 
using namespace std;
long long n,t,a[100005][5],ans;
struct node{
	long long x,i;
	bool operator < (const node &d) const {
		return x>d.x;
	} 
};
priority_queue<node> q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		ans=0;
		while(!q1.empty()){
			q1.pop();
		} 
		while(!q2.empty()){
			q2.pop();
		} 
		while(!q3.empty()){
			q3.pop();
		}
		for(int i=1;i<=n;i++){
			long long x=0,y=0,z=0;
			if(q1.size()<n/2){
				x=a[i][1];
			}else {
				x=a[i][1]+max(a[q1.top().i][2],a[q1.top().i][3])-a[q1.top().i][1];
			}
			if(q2.size()<n/2)y=a[i][2];
			else y=a[i][2]+max(a[q2.top().i][1],a[q2.top().i][3])-a[q2.top().i][2];
			
			if(q3.size()<n/2)z=a[i][3];
			else z=a[i][3]+max(a[q3.top().i][2],a[q3.top().i][1])-a[q3.top().i][3];
			if(x>=y&&x>=z){
				if(q1.size()<n/2)q1.push({a[i][1]-max(a[i][2],a[i][3]),i});
				else{
					if(a[q1.top().i][2]>a[q1.top().i][3]){
						q2.push({a[q1.top().i][2]-max(a[q1.top().i][3],a[q1.top().i][1]),q1.top().i});
						q1.pop();
						q1.push({a[i][1]-max(a[i][2],a[i][3]),i});
					}else{
						q3.push({a[q1.top().i][3]-max(a[q1.top().i][2],a[q1.top().i][1]),q1.top().i});
						q1.pop();
						q1.push({a[i][1]-max(a[i][2],a[i][3]),i});
					}
				}
				ans+=x;
			}else if(y>z){
				if(q2.size()<n/2)q2.push({a[i][2]-max(a[i][1],a[i][3]),i});
				else{
					if(a[q2.top().i][1]>a[q2.top().i][3]){
						q1.push({a[q2.top().i][1]-max(a[q2.top().i][2],a[q2.top().i][3]),q2.top().i});
						q2.pop();
						q2.push({a[i][2]-max(a[i][1],a[i][3]),i});
					}else{
						q3.push({a[q2.top().i][3]-max(a[q2.top().i][1],a[q2.top().i][2]),q2.top().i});
						q2.pop();
						q2.push({a[i][2]-max(a[i][1],a[i][3]),i});
					}
				}
				ans+=y;
			}else{
				if(q3.size()<n/2)q3.push({a[i][3]-max(a[i][2],a[i][1]),i});
				else{
					if(a[q3.top().i][1]>a[q3.top().i][2]){
						q1.push({a[q3.top().i][1]-max(a[q3.top().i][2],a[q3.top().i][3]),q3.top().i});
						q3.pop();
						q3.push({a[i][3]-max(a[i][2],a[i][1]),i});
					}else{
						q2.push({a[q3.top().i][2]-max(a[q3.top().i][3],a[q3.top().i][1]),q3.top().i});
						q3.pop();
						q3.push({a[i][3]-max(a[i][2],a[i][1]),i});
					}
				}
				ans+=z;
			} 
		} 
		cout<<ans<<endl;
	}
	return 0;
}
