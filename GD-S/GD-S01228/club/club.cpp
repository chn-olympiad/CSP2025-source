#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
	int x;
	int y;
	int z;
	int vis;
};
int cmp(node qw,node we){
	if(qw.x!=we.x){
		return qw.x>we.x;
	}
	if(qw.y>we.y){
		return qw.y>we.y;
	}
	if(qw.z>we.z){
		return qw.z>we.z;
	}
}
int cqp(node qw,node we){
	if(qw.z>we.z){
		return qw.z>we.z;
	}
	if(qw.x!=we.x){
		return qw.x>we.x;
	}
	if(qw.y>we.y){
		return qw.y>we.y;
	}
	
}
int cnp(node qw,node we)
	{if(qw.y>we.y){
		return qw.y>we.y;
	}
	if(qw.x!=we.x){
		return qw.x>we.x;
	}
	
	if(qw.z>we.z){
		return qw.z>we.z;
	}
}
node q[20005];
int main(){ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int c;
			cin>>q[i].a>>q[i].b>>c;
			q[i].x=q[i].a-q[i].b-c;
			q[i].y=q[i].b-c-q[i].a;
			q[i].z=c-q[i].a-q[i].b;
		}
		sort(q+1,q+1+n,cmp);
		int yu=0;
		int tu=0;
		int op=0;
		for(int i=1;i<=n/2+op;i++){
			if(q[i].vis==0){
				yu+=q[i].a;
				q[i].vis=1;
			}
			else{
				op++;
			}
		}
		op=0;
		sort(q+1,q+1+n,cnp);
		for(int i=1;i<=n/2+op;i++){
			if(q[i].vis==0){
				yu+=q[i].b;
				q[i].vis=2;
				
			}
			else{
				op++; 
			}
		}
		op=0;
		cout<<yu+tu<<endl;
		for(int i=1;i<=n;i++){
			q[i].a=0;
			q[i].b=0;
			q[i].y=0;
			q[i].x=0;
			q[i].z=0;
			q[i].vis=0;
		}
	}
	return 0;
} 
