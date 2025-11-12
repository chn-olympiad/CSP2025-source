#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int T;
struct node{
	int x,y,z;
	bool operator<(const node &p)const{
		return max(x,max(y,z))>max(p.x,max(p.y,p.z));
	}
}a[N];
struct Q1{
	int k1,k2,k3;
	bool operator<(const Q1 &p)const{
		return k1-max(k2,k3)>p.k1-max(p.k2,p.k3);
	}
};
struct Q2{
	int k1,k2,k3;
	bool operator<(const Q2 &p)const{
		return k2-max(k1,k3)>p.k2-max(p.k1,p.k3);
	}
};
struct Q3{
	int k1,k2,k3;
	bool operator<(const Q3 &p)const{
		return k3-max(k1,k2)>p.k3-max(p.k1,p.k2);
	}
};
priority_queue<Q1>q1;
priority_queue<Q2>q2;
priority_queue<Q3>q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x){
				if(q1.size()<n/2)q1.push({a[i].x,a[i].y,a[i].z});
				else{
					if(q1.top().k1+max(a[i].y,a[i].z)<max(q1.top().k2,q1.top().k3)+a[i].x){
						if(max(q1.top().k2,q1.top().k3)==q1.top().k2)q2.push({q1.top().k1,q1.top().k2,q1.top().k3});
						else q3.push({q1.top().k1,q1.top().k2,q1.top().k3});
						q1.pop();
						q1.push({a[i].x,a[i].y,a[i].z});
					}
					else{
						if(max(a[i].y,a[i].z)==a[i].y)q2.push({a[i].x,a[i].y,a[i].z});
						else q3.push({a[i].x,a[i].y,a[i].z});
					}
				}
			}
			else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y){
				if(q2.size()<n/2)q2.push({a[i].x,a[i].y,a[i].z});
				else{
					if(q2.top().k2+max(a[i].x,a[i].z)<max(q2.top().k1,q2.top().k3)+a[i].y){
						if(max(q2.top().k1,q2.top().k3)==q2.top().k1)q1.push({q2.top().k1,q2.top().k2,q2.top().k3});
						else q3.push({q2.top().k1,q2.top().k2,q2.top().k3});
						q2.pop();
						q2.push({a[i].x,a[i].y,a[i].z});
					}
					else{
						if(max(a[i].x,a[i].z)==a[i].x)q1.push({a[i].x,a[i].y,a[i].z});
						else q3.push({a[i].x,a[i].y,a[i].z});
					}
				}
			}
			else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].z){
				if(q3.size()<n/2)q3.push({a[i].x,a[i].y,a[i].z});
				else{
					if(q3.top().k3+max(a[i].x,a[i].y)<max(q3.top().k1,q3.top().k2)+a[i].z){
						if(max(q3.top().k1,q3.top().k2)==q3.top().k1)q1.push({q3.top().k1,q3.top().k2,q3.top().k3});
						else q2.push({q3.top().k1,q3.top().k2,q3.top().k3});
						q3.pop();
						q3.push({a[i].x,a[i].y,a[i].z});
					}
					else{
						if(max(a[i].x,a[i].y)==a[i].x)q1.push({a[i].x,a[i].y,a[i].z});
						else q2.push({a[i].x,a[i].y,a[i].z});
					}
				}
			}
		}
		long long ans=0;
		while(q1.size())ans+=q1.top().k1,q1.pop();
		while(q2.size())ans+=q2.top().k2,q2.pop();
		while(q3.size())ans+=q3.top().k3,q3.pop();
		printf("%lld\n",ans);
	}
	return 0;
}
