#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,z;
}a[100005];

bool cmp1(node a,node b){
	return a.x>b.x;
}

bool cmp2(node a,node b){
	return abs(a.x-a.y)>abs(b.x-b.y);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long ans=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n==2){
			ans=max(ans,a[1].x+a[0].y);
			ans=max(ans,a[1].x+a[0].z);
			ans=max(ans,a[1].y+a[0].x);
			ans=max(ans,a[1].y+a[0].z);
			ans=max(ans,a[1].z+a[0].y);
			ans=max(ans,a[1].z+a[0].x);
			cout<<ans<<endl;
			return 0;
			}	
		if(n==4){
			for(int i=0;i<4;i++){
				ans=max(ans,a[i].x+a[(i+1)%4].x+a[(i+2)%4].y+a[(i+3)%4].z);
				ans=max(ans,a[i].x+a[(i+1)%4].y+a[(i+2)%4].x+a[(i+3)%4].z);
				ans=max(ans,a[i].x+a[(i+1)%4].x+a[(i+2)%4].z+a[(i+3)%4].y);
				ans=max(ans,a[i].x+a[(i+1)%4].y+a[(i+2)%4].z+a[(i+3)%4].x);
				ans=max(ans,a[i].x+a[(i+1)%4].z+a[(i+2)%4].y+a[(i+3)%4].x);
				ans=max(ans,a[i].x+a[(i+1)%4].z+a[(i+2)%4].x+a[(i+3)%4].y);
				ans=max(ans,a[i].x+a[(i+1)%4].x+a[(i+2)%4].y+a[(i+3)%4].y);
				ans=max(ans,a[i].y+a[(i+1)%4].y+a[(i+2)%4].z+a[(i+3)%4].z);
				ans=max(ans,a[i].z+a[(i+1)%4].z+a[(i+2)%4].x+a[(i+3)%4].x);			
			}
			cout<<ans<<endl;
			return 0;
		}
		int f=0;
		for(int i=0;i<n;i++){
			if(a[i].y!=0||a[i].z!=0){
				f=1;
			} 
		}	
		if(f==0) {
			sort(a+0,a+n,cmp1);
			for(int i=0;i<n/2;i++)
			ans+=a[i].x;
			cout<<ans;
			return 0;
		}
		f=0;
		for(int i=0;i<n;i++){
			if(a[i].z!=0) f=1;
		}
		if(f==0){
			sort(a+0,a+n,cmp2);
			int cnt1=0,cnt2=0,cnt;
			for(int i=0;i<n;i++){
				cnt=i;
				if(cnt1==n/2) break;
				if(cnt2==n/2) break;
				if(a[i].x>a[i].y){
					cnt1++;
					ans+=a[i].x;
				} 
				else{
					cnt2++;
					ans+=a[i].y;
				} 
			}
			if(cnt1==n/2){
				for(int i=cnt;i<n;i++) ans+=a[i].y;
			}
			else for(int i=cnt;i<n;i++) ans+=a[i].x;
			cout<<ans<<endl;
		}
	}
	return 0;
}





