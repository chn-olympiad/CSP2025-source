#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
void solve(){
	int n;
	cin>>n;
	priority_queue<int>a[3];
	long long ans=0;
	pair<int,int>b[3];
	for(int i=1;i<=n;i++){
		b[0].y=0;
		b[1].y=1;
		b[2].y=2;
		scanf("%d%d%d",&b[0].x,&b[1].x,&b[2].x);
		if(b[0].x<b[1].x){
			swap(b[0],b[1]);
		}if(b[1].x<b[2].x){
			swap(b[2],b[1]);
		}if(b[0].x<b[1].x){
			swap(b[0],b[1]);
		}
		if(a[b[0].y].size()<(n>>1)){
			a[b[0].y].push(b[1].x-b[0].x);
			ans+=b[0].x;
		}else{
			if(b[1].x-b[0].x<a[b[0].y].top()){
				ans+=a[b[0].y].top();
				a[b[0].y].pop();
				a[b[0].y].push(b[1].x-b[0].x);
				ans+=b[0].x;
			}else{
				ans+=b[1].x;
			}
		}
		
	
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--)solve();
} 
