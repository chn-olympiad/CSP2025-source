#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,id;
}a[100005],b[100005],c[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;
	cin>>T;
	while(T--){
		int n;
		priority_queue<int,vector<int>,greater<int> > q1,q2,q3;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>b[i].x>>c[i].x;
			a[i].id=1;
			b[i].id=2;
			c[i].id=3;
			if(a[i].x<b[i].x){
				swap(a[i],b[i]);
			} 
			if(b[i].x<c[i].x){
				swap(b[i],c[i]);
			}
			if(a[i].x<b[i].x){
				swap(a[i],b[i]);
			}
			if(a[i].id==1){
				q1.push(a[i].x-b[i].x);
				ans+=a[i].x;
			}else if(a[i].id==2){
				q2.push(a[i].x-b[i].x);
				ans+=a[i].x;
			}else{
				q3.push(a[i].x-b[i].x);
				ans+=a[i].x;
			}
		}
		while(q1.size()>n/2){
			ans-=q1.top();
			q1.pop();
		}
		while(q2.size()>n/2){
			ans-=q2.top();
			q2.pop();
		}
		while(q3.size()>n/2){
			ans-=q3.top();
			q3.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
      _____
     |    |
     | 不 |
     | 挂 |
     | 分 |
     |    |
  ___|    |___ 
 |   保分符  \
 |  保佑代码 \
 |___无bug___\
     |    |
     |    |
     | 不 |
     | 挂 |
     | 分 |
     |____|
*/ 
