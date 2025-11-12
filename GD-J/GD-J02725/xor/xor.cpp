#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct node{
	int l,r;
	node(int a,int b):l(a),r(b){} 
};

bool check(node a,node b){
	int l1=a.l,l2=b.l,r1=a.r,r2=b.r;
	if(l1>=l2&&l1<=r2||r1>=l2&&r1<=r2)return true;
	if(l2>=l1&&l2<=r1||r2>=l1&&r2<=r1)return true;
	return false;
}

int n,k,a[500010],maxn=0;
vector<node> v;
bool bl[500010];

bool che(node a){
	for(int i=1;i<=v.size();i++)
		if(bl[i]&&check(a,v[i]))return true;
	return false;
}

void dfs(int f,int s){
	maxn=max(maxn,s);
	if(f>v.size())return;
	for(int i=1;i<v.size();i++){
		if(f!=i&&!bl[i]){
			if(che(v[i]))continue;
			bl[i]=true;
			dfs(f+1,s+1);
			bl[i]=false;
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	v.push_back(node(0,0));
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=1,r=1,t=a[1];
	for(int l=1;l<=n;l++){t=a[l];
		for(int r=l;r<=n;r++){
			if(l!=r)t^=a[r];
			if(t==k)v.push_back(node(l,r));
		}
	}
	dfs(0,0);
	cout<<maxn;
	return 0;
}
