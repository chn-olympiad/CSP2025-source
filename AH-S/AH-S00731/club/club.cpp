#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans,v1,v2,v3;
struct nude{
	int id,stf,sum;
	bool operator <(const nude &u)const{
		return sum<u.sum;
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		priority_queue<nude> q1,q2,q3;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int mx1=max(a[i][1],max(a[i][2],a[i][3])),place,mx2,check=0;
			if(mx1==a[i][1]){
				if(v1==n/2){
					check=1,mx2=max(a[i][2],a[i][3]);
					if(mx1+q1.top().sum>0){
						place=q1.top().id;
						q1.pop();
						q1.push({i,mx1,mx2-mx1});
						mx2=max(a[place][2],a[place][3]);
					}
					else place=i;
				}
				else q1.push({i,a[i][1],max(a[i][2],a[i][3])-mx1}),v1++;
			}
			else if(mx1==a[i][2]){
				if(v2==n/2){
					check=1,mx2=max(a[i][1],a[i][3]);
					if(mx1+q2.top().sum>0){
						place=q2.top().id;
						q2.pop();
						q2.push({i,mx1,mx2-mx1});
						mx2=max(a[place][1],a[place][3]);
					}
					else place=i;
				}
				else q2.push({i,a[i][2],max(a[i][1],a[i][3])-a[i][2]}),v2++;
			}
			else{
				if(v3==n/2){
					check=1,mx2=max(a[i][1],a[i][2]);
					if(mx1+q3.top().sum>0){
						place=q3.top().id;
						q3.pop();
						q3.push({i,mx1,mx2-mx1});
						mx2=max(a[place][1],a[place][2]);
					}
					else place=i;
				}
				else q3.push({i,a[i][3],max(a[i][1],a[i][2])-a[i][3]}),v3++;
			}
			if(check){
				if(mx2==a[place][1]&&v1<n/2) q1.push({place,mx2,max(a[place][2],a[place][3])-mx2}),v1++;
				else if(mx2==a[place][2]&&v2<n/2) q2.push({place,mx2,max(a[place][1],a[place][3])-mx2}),v2++;
				else q3.push({place,mx2,max(a[place][1],a[place][2])-mx2}),v3++;
			}
		}
		while(!q1.empty()) ans+=q1.top().stf,q1.pop();
		while(!q2.empty()) ans+=q2.top().stf,q2.pop();
		while(!q3.empty()) ans+=q3.top().stf,q3.pop();
		cout<<ans<<endl;
		ans=v3=0;
		v1=v2=0;
	}
}
