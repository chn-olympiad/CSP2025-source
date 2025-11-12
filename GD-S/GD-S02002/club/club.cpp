#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,r;
struct dd{int x,d;}a[N][3];
bool p(dd a,dd b){return a.x>b.x;} 
priority_queue<int,vector<int>,greater<int> >q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;r=0;
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		while(!q3.empty())q3.pop();
		for(int i=1; i<=n; i++){
			for(int j=0; j<3; j++){
				cin>>a[i][j].x;
				a[i][j].d=j;
			}
			sort(a[i],a[i]+3,p);r+=a[i][0].x;
			if(a[i][0].d==0)q1.push(a[i][0].x-a[i][1].x);
			if(a[i][0].d==1)q2.push(a[i][0].x-a[i][1].x);
			if(a[i][0].d==2)q3.push(a[i][0].x-a[i][1].x);
		}
		while(q1.size()>n/2){
			r-=q1.top();
			q1.pop();
		}
		while(q2.size()>n/2){
			r-=q2.top();
			q2.pop();
		}
		while(q3.size()>n/2){
			r-=q3.top();
			q3.pop();
		}
		cout<<r<<"\n";
	}
	return 0;
}
