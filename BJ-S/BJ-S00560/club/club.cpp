#include <bits/stdc++.h>

using namespace std;
const int N=1e5+10;
struct node{
	int a,b,id1,id2;
}v[N];
int t,n;
int cnt[4];
bool cmp2(node nx,node ny){
	return abs(nx.a-nx.b)>abs(ny.a-ny.b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			int k=min(x,min(y,z));
			if(x==k){
				v[i].a=y;
				v[i].b=z;
				v[i].id1=2;
				v[i].id2=3;
			}
			else if(y==k){
				v[i].a=x;
				v[i].b=z;
				v[i].id1=1;
				v[i].id2=3;
			}
			else{
				v[i].a=x;
				v[i].b=y;
				v[i].id1=1;
				v[i].id2=2;
			}
		}
		memset(cnt,0,sizeof(cnt));	
		sort(v+1,v+n+1,cmp2);
		for(int i=1;i<=n;i++){
			int p=v[i].a,q=v[i].b,t1=v[i].id1,t2=v[i].id2;
			//cout<<i<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
			if(p>q){
				if(cnt[t1]<n/2){
					sum+=p;
					cnt[t1]++;
				}
				else{
					sum+=q;
					cnt[t2]++;
				}
			}
			else{
				if(cnt[t2]<n/2){
					sum+=q;
					cnt[t2]++;
				}
				else{
					sum+=p;
					cnt[t1]++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
