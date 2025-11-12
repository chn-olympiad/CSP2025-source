#include<bits/stdc++.h>
using namespace std;
int t,n,a2=0,b2=0,c2=0,d[100011]={0};
struct student{
	int a;//满意度 
	int b;//部门 
	int o;//编号 
};
bool cmp(student a,student b){
	return a.a>b.a;
}
student a[300010];
int main(){
//	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int ans=0;
		a2=0;
		b2=0;
		c2=0;
		for(int j=1;j<=100000;j++){
			d[j]=0;
			a[j].a=0;
			a[j].b=0;
			a[j].o=0;
		}
		for(int j=1;j<=n;j++){
			cin>>a[j*3-2].a>>a[j*3-1].a>>a[j*3].a;
			a[j*3-2].b=1;
			a[j*3-1].b=2;
			a[j*3].b=3;	
			a[j*3-2].o=j;
			a[j*3-1].o=j;
			a[j*3].o=j;
		}
		sort(a+1,a+3*n+1,cmp);
//		for(int j=1;j<=n*3;j++){
//			cout<<a[j].a<<' '<<a[j].b<<' '<<a[j].o<<endl;
//		}
		for(int j=1;j<=n*3;j++){
			//cout<<1<<' '<<j<<' '<<a[j].b;
			if(d[a[j].o]==0){
				if(a[j].b==1&&a2+1<=n/2){
					//cout<<1<<' '<<j<<endl;
					a2++;
					ans+=a[j].a;
					d[a[j].o]=1;
				}
				if(a[j].b==2&&b2+1<=n/2){
					//cout<<1<<' '<<j<<endl;
					b2++;
					ans+=a[j].a;
					d[a[j].o]=1;
				}
				if(a[j].b==3&&c2+1<=n/2){
					//cout<<1<<' '<<j<<endl;
					c2++;
					ans+=a[j].a;
					d[a[j].o]=1;
				}
			} 
			
		}
		cout<<ans<<endl;
	}
//	3
//	4
//	4 2 1
//	3 2 4
//	5 3 4
//	3 5 1
//	4
//	0 1 0
//	0 1 0
//	0 2 0
//	0 2 0
//	2 
//	10 9 8
//	4 0 0
	return 0;
}
