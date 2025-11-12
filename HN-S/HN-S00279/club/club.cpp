#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,k[5];
struct node{
	int x,y,z;
	int t;
}a[N];
bool cmp(node q,node d){
	return q.x>d.x;
}
bool cmm(node q,node d){
	return q.y>d.y;
}
bool cmn(node q,node d){
	return q.z>d.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		memset(k,0,sizeof k);
		for(int i = 1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].t=0;
		}
		sort(a+1,a+1+n,cmp);
		for(int i = 1;i<=n&&k[1]<n/2;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				k[1]++;
				a[i].t=1;
			}
		}
		sort(a+1,a+1+n,cmm);
		for(int i = 1;i<=n&&k[2]<n/2;i++){
			if(a[i].y>=a[i].x&&a[i].y>=a[i].z&&a[i].t==0){
				k[2]++;
				a[i].t=2;
			}
		}
		sort(a+1,a+1+n,cmn);
		for(int i = 1;i<=n&&k[3]<n/2;i++){
			if(a[i].z>=a[i].x&&a[i].z>=a[i].y&&a[i].t==0){
				k[3]++;
				a[i].t=3;
			}
		}
		int cnt=0;
		if(k[1]+k[2]+k[3]==0){
			int ans=0;
			for(int i = 1;i<=n;i++){
				if(a[i].t==1)ans+=a[i].x;
				else if (a[i].t==2) ans+=a[i].y;
				else ans+=a[i].z;
			}
			cout<<ans<<endl;
			continue;
		}
		if(k[1]==n/2)cnt=1;
		else if(k[2]==n/2)cnt=2;
		else cnt=3;
		if(cnt==1){
			sort(a+1,a+1+n,cmm);
			for(int i = 1;i<=n;i++){
				if(a[i].t==0&&(a[i].y>=a[i].z||k[3]==n/2)&&k[2]<n/2)a[i].t=2,k[2]++;
				else if(a[i].t==0) a[i].t=3,k[3]++;
			}
		}
		else if(cnt==2){
			sort(a+1,a+1+n,cmp);
			for(int i = 1;i<=n;i++){
				if(a[i].t==0&&(a[i].x>=a[i].z||k[3]==n/2)&&k[1]<n/2)a[i].t=1,k[1]++;
				else if(a[i].t==0) a[i].t=3,k[3]++;
			}
		}
		else if(cnt==3){
			sort(a+1,a+1+n,cmp);
			for(int i = 1;i<=n;i++){
				if(a[i].t==0&&(a[i].x>=a[i].y||k[2]==n/2)&&k[1]<n/2)a[i].t=1,k[1]++;
				else if(a[i].t==0) a[i].t=2,k[2]++;
			}
		}
		int ans=0;
		for(int i = 1;i<=n;i++){
			if(a[i].t==1)ans+=a[i].x;
			else if (a[i].t==2) ans+=a[i].y;
			else ans+=a[i].z;
		}
		cout<<ans<<endl;
	}
	return 0;
}

