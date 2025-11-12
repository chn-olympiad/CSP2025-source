#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][10];
int mx[100005],mn[100005],mmx[100005],o,u[100005],uu[100005],uuu[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int op=n/2;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q,w,t;
		int sum=0,ans=0,vis=0;
		for(int i=1;i<=n;i++){
			mx[i]=-1;
			mn[i]=INT_MAX;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>mx[i]){
					mx[i]=a[i][j];
					u[i]=j;
				}
				if(a[i][j]<mn[i]){
					mn[i]=a[i][j];
					uuu[i]=j;
				}
			}
			mmx[i]=a[i][6-u[i]-uuu[i]];
			uu[i]=6-u[i]-uuu[i];
		}
		if(u[1]==1){
			q.push({mx[1],1});
			sum+=mx[1];
		}
		else if(u[1]==2){
			w.push({mx[1],1});
			ans+=mx[1];
		}
		else{
			t.push({mx[1],1});
			vis+=mx[1];
		}
		for(int i=2;i<=n;i++){
			if(u[i]==1){
				if(q.size()==op){
					int x=q.top().first;
					int y=q.top().second;
					if(mx[i]>x){
						q.pop();
						q.push({mx[i],i});
						sum-=x;
						sum+=mx[i];
					}
					else{
						if(w.size()<op&&uu[y]==2){
							q.pop();
							q.push({mx[i],i});
							sum-=x;
							sum+=mx[i];
							ans+=mmx[y];
							w.push({mmx[y],y});
						}
						else if(w.size()==op&&uu[y]==2){
							q.pop();
							q.push({mx[i],i});
							sum-=x;
							sum+=mx[i];
							ans+=mn[y];
							w.push({mn[y],y});
						}
						else if(t.size()<op&&uu[y]==3){
							q.pop();
							q.push({mx[i],i});
							sum-=x;
							sum+=mx[i];
							vis+=mmx[y];
							t.push({mmx[y],y});
						}
						else if(t.size()==op&&uu[y]==3){
							q.pop();
							q.push({mx[i],i});
							sum-=x;
							sum+=mx[i];
							vis+=mn[y];
							t.push({mn[y],y});
						}
					}
				}
				else{
					q.push({mx[i],i});
					sum+=mx[i];
				}
			}
			if(u[i]==2){
				if(w.size()==op){
					int x=w.top().first;
					int y=w.top().second;
					if(mx[i]>x){
						w.pop();
						w.push({mx[i],i});
						ans-=x;
						ans+=mx[i];
					}
					else{
						if(q.size()<op&&uu[y]==1){
							w.pop();
							w.push({mx[i],i});
							ans-=x;
							ans+=mx[i];
							sum+=mmx[y];
							q.push({mmx[y],y});
						}
						else if(q.size()==op&&uu[y]==1){
							w.pop();
							w.push({mx[i],i});
							ans-=x;
							ans+=mx[i];
							sum+=mn[y];
							q.push({mn[y],y});
						}
						else if(t.size()<op&&uu[y]==3){
							w.pop();
							w.push({mx[i],i});
							ans-=x;
							ans+=mx[i];
							vis+=mmx[y];
							t.push({mmx[y],y});
						}
						else if(t.size()==op&&uu[y]==3){
							w.pop();
							w.push({mx[i],i});
							ans-=x;
							ans+=mx[i];
							vis+=mn[y];
							t.push({mn[y],y});
						}
					}
				}
				else{
					w.push({mx[i],i});
					ans+=mx[i];
				}
			}
			if(u[i]==3){
				if(t.size()==op){
					int x=t.top().first;
					int y=t.top().second;
					if(mx[i]>x){
						t.pop();
						t.push({mx[i],i});
						vis-=x;
						vis+=mx[i];
					}
					else{
						if(q.size()<op&&uu[y]==1){
							t.pop();
							t.push({mx[i],i});
							vis-=x;
							vis+=mx[i];
							sum+=mmx[y];
							q.push({mmx[y],y});
						}
						else if(q.size()==op&&uu[y]==1){
							t.pop();
							t.push({mx[i],i});
							vis-=x;
							vis+=mx[i];
							sum+=mn[y];
							q.push({mn[y],y});
						}
						else if(w.size()<op&&uu[y]==2){
							t.pop();
							t.push({mx[i],i});
							vis-=x;
							vis+=mx[i];
							ans+=mmx[y];
							w.push({mmx[y],y});
						}
						else if(w.size()==op&&uu[y]==2){
							t.pop();
							t.push({mx[i],i});
							vis-=x;
							vis+=mx[i];
							ans+=mn[y];
							w.push({mn[y],y});
						}
					}
				}
				else{
					t.push({mx[i],i});
					vis+=mx[i];
				}
			}
		}
		cout<<sum+ans+vis<<endl;
	}
	return 0;
}
