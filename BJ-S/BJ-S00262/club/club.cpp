#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
int a[N][5];
int h[5],sum=0;
priority_queue<int> q[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		sum=0;
		h[0]=h[1]=h[2]=h[3]=h[4]=0;
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();

		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				h[1]++;
				sum+=a[i][1];
				q[1].push(-a[i][1]+max(a[i][2],a[i][3]));
			}else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				h[2]++;
				sum+=a[i][2];
				q[2].push(-a[i][2]+max(a[i][1],a[i][3]));
			}else{
				h[3]++;
				sum+=a[i][3];
				q[3].push(-a[i][3]+max(a[i][1],a[i][2]));
			}
		}

		while(h[1]>n/2){
			h[1]--;
			sum+=q[1].top();
			q[1].pop();
		}
		while(h[2]>n/2){
			h[2]--;
			sum+=q[2].top();
			q[2].pop();
		}
		while(h[3]>n/2){
			h[3]--;
			sum+=q[3].top();
			q[3].pop();
		}
		cout<<sum<<"\n";
	}
	return 0;
}
