#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100005
int T,n,siz1,siz2,siz3,inf=1e9;
struct Node{
	int x,y,z;
}a[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		priority_queue<pair<int,pair<int,int>>> q1,q2,q3;
		siz1=siz2=siz3=0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		for(int i = 1;i <= n;i++){
			int mx=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x==mx){
				q1.push({(mx-max(a[i].y,a[i].z))*(-1),{i,mx}});
				siz1++;
				if(siz1>n/2){
					int tmp=q1.top().second.first;
					siz1--;
					q1.pop();
					if(a[tmp].y>a[tmp].z){
						q2.push({-inf,{i,a[tmp].y}});
						siz2++;
					}else{
						q3.push({-inf,{i,a[tmp].z}});
						siz3++;
					}
				} 
			}
			else if(a[i].y==mx){
				q2.push({(mx-max(a[i].x,a[i].z))*(-1),{i,mx}});
				siz2++;
				if(siz2>n/2){
					int tmp=q2.top().second.first;
					siz2--;
					q2.pop();
					if(a[tmp].x>a[tmp].z){
						q1.push({-inf,{i,a[tmp].x}});
						siz1++;
					}else{
						q3.push({-inf,{i,a[tmp].z}});
						siz3++;
					}
				} 
			}
			else if(a[i].z==mx){
				q3.push({(mx-max(a[i].x,a[i].y))*(-1),{i,mx}});
				siz3++;
				if(siz3>n/2){
					int tmp=q3.top().second.first;
					siz3--;
					q3.pop();
					if(a[tmp].x>a[tmp].y){
						q1.push({-inf,{i,a[tmp].x}});
						siz1++;
					}else{
						q2.push({-inf,{i,a[tmp].y}});
						siz2++;
					}
				} 
			}
		}
		int ans=0;
		while(!q1.empty()){
//			cout << q1.top().first*(-1) << " ";
			ans+=(q1.top().second.second);
			q1.pop();
		}
//		cout << endl;
		while(!q2.empty()){
//			cout << q2.top().first*(-1) << " ";
			ans+=(q2.top().second.second);
			q2.pop();
		}
//		cout << endl;
		while(!q3.empty()){
//			cout << q3.top().first*(-1) <<" ";
			ans+=(q3.top().second.second);
			q3.pop();
		}
//		cout << endl;
		cout << ans << endl;
	} 
	return 0;
} 
