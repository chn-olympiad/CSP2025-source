#include<bits/stdc++.h>
using namespace std;
int t;
struct stu{
	int x,y,z,sum,n;
}a[100010];
int s[4];
bool cnt1(stu x,stu y){
	if(x.x==y.x)return max(x.y,x.z)<max(y.y,y.z);
	return x.x>y.x;
}bool cnt2(stu x,stu y){
	if(x.y==y.y)return max(x.x,x.z)<max(y.x,y.z);
	return x.y>y.y;
}bool cnt3(stu x,stu y){
	if(x.z==y.z)return max(x.x,x.y)<max(y.x,y.y);
	return x.z>y.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		s[1]=0,s[2]=0,s[3]=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y && a[i].x>=a[i].z)
				a[i].n=1;
			else if(a[i].y>=a[i].x && a[i].y>=a[i].z)
				a[i].n=2;
			else if(a[i].z>=a[i].x && a[i].z>=a[i].y)
				a[i].n=3;
			a[i].sum=max(a[i].x,max(a[i].y,a[i].z));
			s[a[i].n]++;
		}
		if(s[1]>(n/2)){
			sort(a+1,a+n+1,cnt1);
			for(int i=n/2+1;i<=s[1];i++){
				a[i].n=(a[i].y>a[i].z)?2:3;
				a[i].sum=max(a[i].y,a[i].z);
			}
		}
		else if(s[2]>(n/2)){
			sort(a+1,a+n+1,cnt2);
			for(int i=n/2+1;i<=s[2];i++){
				a[i].n=(a[i].x>a[i].z)?1:3;
				a[i].sum=max(a[i].x,a[i].z);
			}
		}
		else if(s[3]>(n/2)){
			sort(a+1,a+n+1,cnt3);
			for(int i=n/2+1;i<=s[3];i++){
				a[i].n=(a[i].x>a[i].y)?1:2;
				a[i].sum=max(a[i].x,a[i].y);
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].n==1)ans+=a[i].x;
			if(a[i].n==2)ans+=a[i].y;
			if(a[i].n==3)ans+=a[i].z;
		}
		cout<<ans<<endl;
	}
	if(t>=6)cout<<"CCFÄãÊ²Ã´ÒâË¼£¿"; 
	return 0;
}
