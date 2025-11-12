#include<bits/stdc++.h>
using namespace std;
int t;
priority_queue<int> pq;
int a1[100005][5]={0};
int zu[5]={0};
int n;
void pailie(int x,int sum,int a[100005][5]){
	if(x==n+1){
		pq.push(sum);
		return;
	}
	int k=sum;
	for(int i=x;i<=n;i++){
		int p=max(a[i][1],a[i][2]);
		p=max(a[i][3],p);
		k+=p;
	}
	if(k<=pq.top()){
		return;
	}
	for(int i=1;i<=3;i++){
		int t=n/2;
		if(zu[i]+1<=t){
			sum+=a[x][i];
			zu[i]++;
			pailie(x+1,sum,a);
			zu[i]--;
			sum-=a[x][i];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		while(!pq.empty()){
			pq.pop();
		}
		pq.push(-1);
		int y;
		cin>>y;
		n=y;
		for(int j=1;j<=n;j++){
			int x1;
			int x2;
			int x3;
			cin>>x1>>x2>>x3;
			a1[j][1]=x1;
			a1[j][2]=x2;
			a1[j][3]=x3;
		}
		pailie(1,0,a1);
		cout<<pq.top()<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
