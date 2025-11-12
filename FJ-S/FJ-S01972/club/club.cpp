#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int T,n;
ll ans,v[N][5];
int a[N][5],cnt1,cnt2,cnt3;
priority_queue<pair<ll,int>>q1,q2,q3;
int main(){
//	freopen("test.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			v[i][1]=a[i][1],v[i][2]=a[i][2],v[i][3]=a[i][3];
			sort(v[i]+1,v[i]+4);
		}
		for(int i=1;i<=n;i++){
			if(v[i][3]==a[i][1]){
				if(cnt1<n/2){
					cnt1++;
					q1.push({-a[i][1],i});
				}
				else{
					ll t=-q1.top().first;int id=q1.top().second;
					q1.pop();
					if(t-v[id][2]<a[i][1]-v[i][2]){
						q1.push({-a[i][1],i});
						if(v[id][2]==a[id][2]){
							cnt2++;
							q2.push({-a[id][2],id});
						}
						else{
							cnt3++;
							q3.push({-a[id][3],id});
						}
					}
					else if(t-v[id][2]>=a[i][1]-v[i][2]){
						q1.push({-t,id});
						if(v[i][2]==a[i][2]){
							cnt2++;
							q2.push({-a[i][2],i});
						}
						else{
							cnt3++;
							q3.push({-a[i][3],i});
						}
					}
				}
			}
			else if(v[i][3]==a[i][2]){
				if(cnt2<n/2){
					cnt2++;
					q2.push({-a[i][2],i});
				}
				else{
					ll t=-q2.top().first;int id=q2.top().second;
					q2.pop();
					if(t-v[id][2]<a[i][2]-v[i][2]){
						q2.push({-a[i][2],i});
						if(v[id][2]==a[id][1]){
							cnt1++;
							q1.push({-a[id][1],id});
						}
						else{
							cnt3++;
							q3.push({-a[id][3],id});
						}
					}
					else if(t-v[id][2]>=a[i][2]-v[i][2]){
						q2.push({-t,id});
						if(v[i][2]==a[i][1]){
							cnt1++;
							q1.push({-a[i][1],i});
						}
						else{
							cnt3++;
							q3.push({-a[i][3],i});
						}
					}
				}
			}
			else if(v[i][3]==a[i][3]){
				if(cnt3<n/2){
					cnt3++;
					q3.push({-a[i][3],i});
				}
				else{
					ll t=-q3.top().first;int id=q3.top().second;
					q3.pop();
					if(t-v[id][2]<a[i][3]-v[i][2]){
						q3.push({-a[i][3],i});
						if(v[id][2]==a[id][2]){
							cnt2++;
							q2.push({-a[id][2],id});
						}
						else{
							cnt1++;
							q1.push({-a[id][1],id});
						}
					}
					else if(t-v[id][2]>=a[i][3]-v[i][2]){
						q3.push({-t,id});
						if(v[i][2]==a[i][2]){
							cnt2++;
							q2.push({-a[i][2],i});
						}
						else{
							cnt1++;
							q1.push({-a[i][1],i});
						}
					}
				}
			}
		}
//		cout<<"--------\n";
		while(!q1.empty()){
			ans-=q1.top().first;
//			cout<<q1.top().second<<' ';
			q1.pop();
		}
//		cout<<'\n';
		while(!q2.empty()){
			ans-=q2.top().first;
//			cout<<q2.top().second<<' ';
			q2.pop();
		}
//		cout<<'\n';
		while(!q3.empty()){
			ans-=q3.top().first;
//			cout<<q3.top().second<<' ';
			q3.pop();
		}
//		cout<<'\n';
		cout<<ans<<'\n';
//		cout<<'\n';
		ans=0ll,cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++) a[i][1]=a[i][2]=a[i][3]=0,v[i][1]=v[i][2]=v[i][3]=0ll;
	}
	return 0;
} 
