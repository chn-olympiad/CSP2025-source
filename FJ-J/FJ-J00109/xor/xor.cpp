#include<bits/stdc++.h>
using namespace std;

int r[500010];
struct node{
	int x,y;
};
int cmp(node a,node b){
	return a.y-a.x>b.y-b.x;
}
bool check(int a,int b,int c,int d){
	if(b<c||d<a) return true;
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	vector<node>q;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		int ans=r[i];
		for(int j=i;j<=n;j++){
			if(j!=i) ans^=r[j];
			if(ans==k){
				q.push_back((node){i,j});
				break;
			}
		}
	}
	sort(q.begin(),q.end(),cmp);
	for(int i=0;i<q.size();i++){
		int flag=1;
		for(int j=i+1;j<q.size();j++){
			node now=q[i],next=q[j];
			int x_0=now.x , y_0=now.y;
			int x_1=next.x , y_1=next.y;
			if(!check(x_0,y_0,x_1,y_1)){
				flag=0;
			}
		}
		if(flag) cnt++;
	}
	cout<<cnt;
	return 0;
}
