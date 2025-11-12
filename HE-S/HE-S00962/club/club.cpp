#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5;
int t,n,dis[N];
struct ac{
	int x,y,z;
	int sum,maxn,idx;
}s[N];
bool cmp(ac x,ac y){
	return x.x>y.x;
}
bool cmp1(ac x,ac y){
	return x.x>y.x;
}
bool cmp2(ac x,ac y){
	return x.y>y.y;
}
bool cmp3(ac x,ac y){
	return x.z>y.z;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		bool r=true;
		cin>>n;
		memset(dis,0,sizeof(dis));
		for(int i=1;i<=n;i++){
			cin>>s[i].x>>s[i].y>>s[i].z;
			if(s[i].z!=0&&s[i].y!=0){
				r=false;
			}
			s[i].sum=s[i].x+s[i].y+s[i].z;
			if(s[i].x>s[i].y&&s[i].x>s[i].z){
				s[i].maxn=s[i].x;
				s[i].idx=1;
			}else if(s[i].y>s[i].x&&s[i].y>s[i].z){
				s[i].maxn=s[i].y;
				s[i].idx=2;
			}else if(s[i].z>s[i].x&&s[i].z>s[i].y){
				s[i].maxn=s[i].z;
				s[i].idx=3;
			}
		}
		if(n==2){
			int s1,s2,s3,s4,s5,s6;
			s1=s[1].x+s[2].y;
			s2=s[1].x+s[2].z;
			s3=s[1].y+s[2].x;
			s4=s[1].y+s[2].z;
			s5=s[1].z+s[2].x;
			s6=s[1].z+s[2].y;
			s1=max(s1,s2);
			s3=max(s3,s4);
			s5=max(s5,s6);
			cout<<max(s1,max(s3,s5))<<"\n";
			continue;
		}else if(r==true){
			sort(s+1,s+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=s[i].x;
			}
			cout<<ans<<"\n";
		}else{
			int cnt1=0,cnt2=0,cnt3=0;
			sort(s+1,s+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				cnt1+=s[i].x;
			}
			sort(s+1,s+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				cnt2+=s[i].y;
			}
			sort(s+1,s+1+n,cmp3);
			for(int i=1;i<=n/2;i++){
				cnt3+=s[i].z;
			}
			if(cnt1>cnt2&&cnt1>cnt3){
				sort(s+1,s+1+n,cmp1);
				if((n/2)%2==1){
					int sum1=0,sum2=0;
					for(int i=n/2+1;i<=(n/2+n)/2;i++){
						sum1+=s[i].y;
					}
					for(int i=(n/2+n)/2+1;i<=n;i++){
						sum2+=s[i].z;
					}
					int sum3=0,sum4=0;
					for(int i=n/2+1;i<=(n/2+n)/2+1;i++){
						sum3+=s[i].y;
					}
					for(int i=(n/2+n)/2+2;i<=n;i++){
						sum4+=s[i].z;
					}
					if(sum1+sum2>sum3+sum4){
						cout<<cnt1+sum1+sum2<<"\n";
					}else{
						cout<<cnt1+sum3+sum4<<"\n";
					}
				}else{
					int sum1=0,sum2=0;
					for(int i=n/2+1;i<=(n/2+n)/2;i++){
						sum1+=s[i].y;
					}
					for(int i=(n/2+n)/2+1;i<=n;i++){
						sum2+=s[i].z;
					}
					int sum3=0,sum4=0;
					for(int i=n/2+1;i<=(n/2+n)/2+1;i++){
						sum3+=s[i].z;
					}
					for(int i=(n/2+n)/2+2;i<=n;i++){
						sum4+=s[i].y;
					}
					if(sum1+sum2>sum3+sum4){
						cout<<cnt1+sum1+sum2<<"\n";
					}else{
						cout<<cnt1+sum3+sum4<<"\n";
					}
				}
			}else if(cnt2>cnt1&&cnt2>cnt3){
				sort(s+1,s+1+n,cmp2);
				if((n/2)%2==1){
					int sum1=0,sum2=0;
					for(int i=n/2+1;i<=(n/2+n)/2;i++){
						sum1+=s[i].x;
					}
					for(int i=(n/2+n)/2+1;i<=n;i++){
						sum2+=s[i].z;
					}
					int sum3=0,sum4=0;
					for(int i=n/2+1;i<=(n/2+n)/2+1;i++){
						sum3+=s[i].x;
					}
					for(int i=(n/2+n)/2+2;i<=n;i++){
						sum4+=s[i].z;
					}
					if(sum1+sum2>sum3+sum4){
						cout<<cnt2+sum1+sum2<<"\n";
					}else{
						cout<<cnt2+sum3+sum4<<"\n";
					}
				}else{
					int sum1=0,sum2=0;
					for(int i=n/2+1;i<=(n/2+n)/2;i++){
						sum1+=s[i].x;
					}
					for(int i=(n/2+n)/2+1;i<=n;i++){
						sum2+=s[i].z;
					}
					int sum3=0,sum4=0;
					for(int i=n/2+1;i<=(n/2+n)/2+1;i++){
						sum3+=s[i].z;
					}
					for(int i=(n/2+n)/2+2;i<=n;i++){
						sum4+=s[i].x;
					}
					if(sum1+sum2>sum3+sum4){
						cout<<cnt2+sum1+sum2<<"\n";
					}else{
						cout<<cnt2+sum3+sum4<<"\n";
					}
				}
			}else if(cnt3>cnt1&&cnt3>cnt2){
				sort(s+1,s+1+n,cmp3);
				if((n/2)%2==1){
					int sum1=0,sum2=0;
					for(int i=n/2+1;i<=(n/2+n)/2;i++){
						sum1+=s[i].y;
					}
					for(int i=(n/2+n)/2+1;i<=n;i++){
						sum2+=s[i].x;
					}
					int sum3=0,sum4=0;
					for(int i=n/2+1;i<=(n/2+n)/2+1;i++){
						sum3+=s[i].y;
					}
					for(int i=(n/2+n)/2+2;i<=n;i++){
						sum4+=s[i].x;
					}
					if(sum1+sum2>sum3+sum4){
						cout<<cnt3+sum1+sum2<<"\n";
					}else{
						cout<<cnt3+sum3+sum4<<"\n";
					}
				}else{
					int sum1=0,sum2=0;
					for(int i=n/2+1;i<=(n/2+n)/2;i++){
						sum1+=s[i].y;
					}
					for(int i=(n/2+n)/2+1;i<=n;i++){
						sum2+=s[i].x;
					}
					int sum3=0,sum4=0;
					for(int i=n/2+1;i<=(n/2+n)/2+1;i++){
						sum3+=s[i].x;
					}
					for(int i=(n/2+n)/2+2;i<=n;i++){
						sum4+=s[i].y;
					}
					if(sum1+sum2>sum3+sum4){
						cout<<cnt3+sum1+sum2<<"\n";
					}else{
						cout<<cnt3+sum3+sum4<<"\n";
					}
				}
			}
		}
	}
	return 0;
}
/*
3 6 10 15

5 3 4
3 2 4
3 5 1
4 2 1


*/
