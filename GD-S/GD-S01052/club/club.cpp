#include <bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int club;
	int value;
	bool operator < (const node& other)const{
		return value<other.value;
	}
};
priority_queue<node>q;
int t,n,ans;
int club[3];
bool ren[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		while(!q.empty())q.pop();
		cin>>n;
		for(int i=0;i<n;i++){
			ren[i]=false;
			for(int j=0,tmp;j<3;j++){
				cin>>tmp;
				q.push({i,j,tmp});
			}
		}
		int cnt=0;
		club[0]=club[1]=club[2]=0;
		while(cnt!=n){
			node qt=q.top();
			q.pop();
			if(ren[qt.id]||club[qt.club]>n/2)continue;
			else{
				cnt++;
				club[qt.club]++;
				ren[qt.id]=true; 
				ans+=qt.value;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
