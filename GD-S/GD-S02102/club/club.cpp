#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int t,n,a[N],s1,s2,s3,k,flag;//a[i][j]表示i转到部门j的代价 
ll sum;
priority_queue<int,vector<int>,greater<int> > q1,q2,q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0,s1=0,s2=0,s3=0,k=0,flag=0;
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				a[i]=min(x-y,x-z);
				s1++;
				if(s1>n/2) k++,flag=1;
				sum+=x;
				q1.push(a[i]);
			}
			else if(y>x&&y>z){
				a[i]=min(y-x,y-z);
				s2++;
				if(s2>n/2) k++,flag=2;
				sum+=y;
				q2.push(a[i]);
			}
			else if(z>x&&z>y){
				a[i]=min(z-x,z-y);
				s3++;
				if(s3>n/2) k++,flag=3;
				sum+=z;
				q3.push(a[i]);
			}
		}
		if(flag==1){
			for(int i=1;i<=k;i++){
				sum-=q1.top();
				q1.pop();
			}
		}
		if(flag==2){
			for(int i=1;i<=k;i++){
				sum-=q2.top();
				q2.pop();
			}
		}
		if(flag==3){
			for(int i=1;i<=k;i++){
				sum-=q3.top();
				q3.pop();
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
