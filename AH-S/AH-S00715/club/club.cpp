#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n,maxn;
struct node{
	int x,y,z;
}a[100005];
int s1[100005],s2[100005],s3[100005];
int p[100005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int l1,l2,l3;
		l1=l2=l3=0;
		int su=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				s1[++l1]=i;
				su+=a[i].x;
			}
			else if(a[i].y>a[i].z){
				s2[++l2]=i;
				su+=a[i].y;
			}
			else{
				s3[++l3]=i;
				su+=a[i].z;
			}
		}
		if(l1>l2&&l1>l3){
			if(l1>n/2){
				for(int i=1;i<=l1;i++){
					p[i]=min(a[s1[i]].x-a[s1[i]].y,a[s1[i]].x-a[s1[i]].z);
				}
				sort(p+1,p+l1+1);
				int num=0;
				for(int i=1;i<=l1-n/2;i++){
					num+=p[i];
				}
				cout<<su-num;
			}
			else{
				cout<<su;
			}
		}
		else if(l2>l3){
			if(l2>n/2){
				for(int i=1;i<=l2;i++){
					p[i]=min(a[s2[i]].y-a[s2[i]].x,a[s2[i]].y-a[s2[i]].z);
				}
				sort(p+1,p+l2+1);
				int num=0;
				for(int i=1;i<=l2-n/2;i++){
					num+=p[i];
				}
				cout<<su-num;
			}
			else{
				cout<<su;
			}
		}
		else{
			if(l3>n/2){
				for(int i=1;i<=l3;i++){
					p[i]=min(a[s3[i]].z-a[s3[i]].y,a[s3[i]].z-a[s3[i]].x);
				}
				sort(p+1,p+l3+1);
				int num=0;
				for(int i=1;i<=l3-n/2;i++){
					num+=p[i];
				}
				cout<<su-num;
			}
			else{
				cout<<su;
			}
		}
		cout<<'\n';
	}
	return 0;
}
