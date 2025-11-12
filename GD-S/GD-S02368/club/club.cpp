#include<bits/stdc++.h>
using namespace std;
int t;
int n;
long long sum;
struct node{
	int x,y,z;
	int id;
}a[100010];
bool cmp(node l,node r){
	return max(l.x,max(l.y,l.z))>max(r.x,max(r.y,r.z));
}
int main(){
//	freopen("club1.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		int s1=0,s2=0,s3=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int x=a[i].x,y=a[i].y,z=a[i].z;
			if(x>=y&&x>=z&&s1<=n/2)
		} 
	}
	return 0;
} 
