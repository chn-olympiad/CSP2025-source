#include<bits/stdc++.h>
#define _(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
using ll=long long ;
const int maxn=1e5+10;
int t;
int a[maxn][5],tmp[5],cost[maxn][5];
void solve(int p){
	int sum=0;
	memset(tmp,0,sizeof tmp);
    _(i,1,3){
    	priority_queue<int> q;
    	_(j,1,p){
    		q.push(cost[j][i]);
		}
		while(q.size()&&tmp[i]<=p/2){
			int nd=q.top();
			q.pop();
			if(nd>=q.top()){
				tmp[i]++;
				sum+=nd;
			}
		}
		if(q.size()<p/2){
			while(q.size()){
				sum+=q.top();
				q.pop();
			}
		}
	}
	cout<<sum<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(tmp,0,sizeof tmp);
		memset(a,0,sizeof a);
		memset(cost,0,sizeof cost);
		int n;
		bool flag=false;
		cin>>n;
		_(i,1,n){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			cost[i][1]=a[i][1];
			cost[i][2]=a[i][2];
			cost[i][3]=a[i][3];
		}    
		_(i,1,n){
			int maxx=-0x3f3f3f;
			int pos=0;
			int cnt=0;
			_(j,1,3){
				if(maxx<=a[i][j]){
					maxx=a[i][j];
				    pos=j;
				}
			}
//			_(j,1,3) cout<<cost[i][j]<<" ";
//			cout<<endl;
			tmp[pos]++;
		}
		int sum=0;
		_(i,1,3){
			if(tmp[i]>n/2) flag=1;
		}
		if(!flag){
			int maxx2=-0x3f3f3f;
			_(i,1,n){
				_(j,1,3){
					maxx2=max(maxx2,cost[i][j]);
				}
			    sum+=maxx2;
			}
			cout<<sum<<endl;
		}else{
			solve(n);
		}
	}
	return 0;
}
//a1,1+a2,2+a3,3;
