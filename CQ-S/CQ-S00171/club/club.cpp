#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int t,n;
struct node{
	int a,b,c;
	
}arr[100005];
struct node2{
	int w,id;
};
bool operator<(node2 a,node2 b){
	return a.w>b.w;
	
} 
priority_queue<node2>pq1;
priority_queue<node2>pq2;
priority_queue<node2>pq3;
int ans=0;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			if(arr[i].a>=arr[i].b&&arr[i].a>=arr[i].c){
				pq1.push({min({abs(arr[i].a-arr[i].b),abs(arr[i].a-arr[i].c)}),i});
				
			}
			else if(arr[i].b>=arr[i].a&&arr[i].b>=arr[i].c){
				pq2.push({min({abs(arr[i].a-arr[i].b),abs(arr[i].c-arr[i].b)}),i});
				
			}
			else if(arr[i].c>=arr[i].b&&arr[i].c>=arr[i].a){
				pq3.push({min({abs(arr[i].c-arr[i].b),abs(arr[i].a-arr[i].c)}),i});
				
			}
		}
		int aa=0,bb=0,cc=0;
		while(pq1.size()>n/2){
			//aa=1;
			node2 aa=pq1.top();
			pq1.pop();
			if(arr[aa.id].a-arr[aa.id].b<arr[aa.id].a-arr[aa.id].c)
			{
				pq2.push(aa);
				
			}
			else pq3.push(aa);
			
		}
		while(pq2.size()>n/2){
			//bb=1;
			node2 aa=pq2.top();
			pq2.pop();
			if(arr[aa.id].b-arr[aa.id].a<arr[aa.id].b-arr[aa.id].c)
			{
				pq1.push(aa);
				
			}
			else pq3.push(aa);
			
		}
		while(pq3.size()>n/2){
			//cc=1;
			node2 aa=pq3.top();
			pq3.pop();
			if(arr[aa.id].c-arr[aa.id].a<arr[aa.id].c-arr[aa.id].b)
			{
				pq1.push(aa);
				
			}
			else pq2.push(aa);
			
		}
		while(pq1.empty()==0){
			ans+=arr[pq1.top().id].a;
			//cout<<pq1.top().w<<' ';
			pq1.pop();
			
		}
		//cout<<'\n';
		while(pq2.empty()==0){
			ans+=arr[pq2.top().id].b;
			//cout<<pq2.top().w<<' ';
			pq2.pop();
			
		}
		//cout<<'\n';
		while(pq3.empty()==0){
			ans+=arr[pq3.top().id].c;
			//cout<<pq3.top().w<<' ';
			pq3.pop();
			
		}
		//cout<<'\n';
		//if(aa+bb+cc>1)cout<<"hjy";
		cout<<ans<<'\n';
	} 
	return 0;
	
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0


*/
