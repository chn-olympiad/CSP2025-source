#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
#define ll long long
#define pii pair<int,int> 
#define fir first
#define sec second
#define mkpir make_pair

//void opened(){
//}

int n;
int a[N][10];
int to[N];
int cnt[10];
bool vis[N];
int ans;
int cntt;

struct people{
	int id,val,to;
};

people mkp(int id,int val,int to){
	return people{id,val,to};
}

struct cmp{
	bool operator()(people A,people B){
		return A.val<B.val;
	}
};

priority_queue<people,vector<people>,cmp> pq;

int main(){
//	opened();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 

	int t;
	cin>>t;
	for(int rp=1;rp<=t;rp++){
		
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		ans=0,cntt=0;
		
		cin>>n;
		
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			ans+=max({a[i][1],a[i][2],a[i][3]});
			
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt[1]++;
				to[i]=1;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				cnt[2]++;
				to[i]=2;
			}else{
				cnt[3]++;
				to[i]=3;
			}
		}
		
		int maxx=1;
		if(cnt[2]>cnt[maxx]){
			maxx=2;
		}
		
		if(cnt[3]>cnt[maxx]){
			maxx=3;
		}
		
		priority_queue<int,vector<int>,greater<int>> pq;
		
		if(cnt[maxx]>n/2){
//			cout<<"flag\n";
			for(int i=1;i<=n;i++){
				if(to[i]==maxx){
					
					if(maxx==1){
						pq.push(min(a[i][maxx]-a[i][2],a[i][maxx]-a[i][3]));
					}
					if(maxx==2){
						pq.push(min(a[i][maxx]-a[i][1],a[i][maxx]-a[i][3]));
					}
					
					if(maxx==3){
						pq.push(min(a[i][maxx]-a[i][1],a[i][maxx]-a[i][2]));
					}
				}
			}
			int cntt=cnt[maxx];
//			cout<<cntt<<" "<<n<<endl;
			while(cntt>(n/2)){
				cntt--;
//				cout<<"ds"<<pq.top()<<endl;
				ans-=pq.top();pq.pop();
			}
		}
		
		cout<<ans<<endl;
		
	}
	
		
	return 0;
}
 
/*
rp+++++++++++;
*/
