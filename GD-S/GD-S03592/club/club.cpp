#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int x,y,z;
	int clb;
}a[100005];
vector<node>cl1;
vector<node>cl2;
vector<node>cl3;
bool cmp(node x,node y){
	if(x.clb==1){
		return x.x-max(x.y , x.z) < y.x-max(y.y , y.z); 
	}
	if(x.clb==2){
		return x.y-max(x.x , x.z) < y.y-max(y.x , y.z);
	}
	if(x.clb==3){
		return x.z-max(x.x , x.y) < y.z-max(y.x , y.y);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int t;
	cin>>t;
	while(t--){
		cl1.clear();
		cl2.clear();
		cl3.clear();
		long long sum=0;
		cin>>n;
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>a[i].x>>a[i].y>>a[i].z;
			x=a[i].x,  y=a[i].y,  z=a[i].z;
			if(x>=y&&x>=z)a[i].clb=1,cl1.push_back(a[i]),sum+=x;
			else if(y>=x&&y>=z)a[i].clb=2,cl2.push_back(a[i]),sum+=y;
			else if(z>=x&&z>=y)a[i].clb=3,cl3.push_back(a[i]),sum+=z;
		}
		sort(cl1.begin(),cl1.end(),cmp);
		sort(cl2.begin(),cl2.end(),cmp);
		sort(cl3.begin(),cl3.end(),cmp);
		
		int len1=cl1.size(),i=0;
		while(len1>n/2){
			sum=sum-cl1[i].x+max(cl1[i].y,cl1[i].z);
			i++,len1--;
		}
		
		int len2=cl2.size();
		i=0;
		while(len2>n/2){
			sum=sum-cl2[i].y+max(cl2[i].x,cl2[i].z);
			i++,len2--;
		}
		
		int len3=cl3.size();
		i=0;
		while(len3>n/2){
			sum=sum-cl3[i].z+max(cl3[i].x,cl3[i].y);
			i++,len3--;
		}
		cout<<sum<<endl; 
	}
	return 0;
}
