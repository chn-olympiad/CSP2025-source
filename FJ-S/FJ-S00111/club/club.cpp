#include<bits/stdc++.h>
using namespace std;

const int N=100010;
struct node{
	int x,y,z;
}a[N]
int cmp(node p,node q){
	return p.x>q.x;
}
int cmp2(node p,node q){
	int maxp=max(p.x,p.y);
	int maxq=max(q.x,q.y);
	return maxp>=maxq;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int flag=0;
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y==0||a[i].z==0) flag++;
		}
		if(flag==2*n){
			sort(a,a+n,cmp);
			int ans=0
			for(int i=0;i<n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<endl;
			continue;
		}
		if(flag==n){
			sort(a,a+n,cmp2);
			int ans=0;
			int cnt1=0,cnt2=0;
			for(int i=0;i<n;i++){
				if(cnt1==n/2){
					ans+=a[i].y;
					cnt2++;
				}
				else if(cnt2==n/2){
					ans+=a[i].x;
					cnt1++;
				}
				else{
					if(a[i].x>=a[i].y){
						ans+=a[i].x;
						cnt1++;
					}else{
						ans+=a[i].y;
						cnt2++;
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
