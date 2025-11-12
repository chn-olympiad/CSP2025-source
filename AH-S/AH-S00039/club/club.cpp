#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct stu{
	int a,b,c;
	int x,y,z;
}f[100005];
bool cmp1(stu p,stu q){
	return p.x>q.x;
}
bool cmp2(stu p,stu q){
	return p.y>q.y;
}
bool cmp3(stu p,stu q){
	return p.z>q.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			f[i].a=0,f[i].b=0,f[i].c=0;
		}
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
			f[i].x=min(f[i].a-f[i].b,f[i].a-f[i].c);
			f[i].y=min(f[i].b-f[i].a,f[i].b-f[i].c);
			f[i].z=min(f[i].c-f[i].a,f[i].c-f[i].b);
		}
		long long sum1=0,sum2=0,sum3=0,sum4=0;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			if(f[i].a>=f[i].b&&f[i].a>=f[i].c){
				sum4+=f[i].a;
				cnt1++;
			}
			else if(f[i].b>=f[i].a&&f[i].b>=f[i].c){
				sum4+=f[i].b;
				cnt2++;
			}
			else {
				sum4+=f[i].c;
				cnt3++;
			}
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			cout<<sum4<<"\n";
			continue;
		}
		sort(f+1,f+n+1,cmp1);
		for(int i=1;i<=n/2;i++){
			sum1+=f[i].a;
		}
		for(int i=n/2+1;i<=n;i++){
			sum1+=max(f[i].b,f[i].c);
		}
		sort(f+1,f+n+1,cmp2);
		for(int i=1;i<=n/2;i++){
			sum2+=f[i].b;
		}
		for(int i=n/2+1;i<=n;i++){
			sum2+=max(f[i].a,f[i].c);
		}
		sort(f+1,f+n+1,cmp3);
		for(int i=1;i<=n/2;i++){
			sum3+=f[i].c;
		}
		for(int i=n/2+1;i<=n;i++){
			sum3+=max(f[i].a,f[i].b);
		}
		cout<<max(sum3,max(sum1,sum2))<<"\n";
	}
	return 0;
}
