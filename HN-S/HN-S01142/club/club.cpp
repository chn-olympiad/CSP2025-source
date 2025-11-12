#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,f[10];
struct node{
	int num1,num2,id1,id2;
	int max1,max2,wz1,wz2;
}a[N];
int cmp(node u,node v){
	if(u.num1==v.num1)return u.num2>v.num2;
	return u.num1>v.num1;
}
int cmpp(node u,node v){
	if(u.max1==v.max1)return u.max2>v.max2;
	return u.max1>v.max1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n,ans=0,zh=0,qq;
		bool flag1=0,flag2=0;
		cin>>n;
		qq=n/2;
		f[1]=f[2]=f[3]=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(y)flag1=1;
			if(z)flag2=1;
			a[i].max1=max(x,y);
			a[i].max2=min(x,y);
			if(a[i].max1==x)a[i].wz1=1,a[i].wz2=3;
			else a[i].wz1=3,a[i].wz2=1;
			if(x>=y&&x>=z){
				a[i].num1=x,a[i].id1=1;
				if(y>=z){
					a[i].num2=y,a[i].id2=2;	
				}
				else{
					a[i].num2=z,a[i].id2=3;
				}
			}
			else if(y>=x&&y>=z){
				a[i].num1=y,a[i].id1=2;
				if(x>=z){
					a[i].num2=x,a[i].id2=1;	
				}
				else{
					a[i].num2=z,a[i].id2=3;
				}
			}
			else{
				a[i].num1=z,a[i].id1=3;
				if(x>=y){
					a[i].num2=x,a[i].id2=1;	
				}
				else{
					a[i].num2=y,a[i].id2=2;
				}
			}
		}
		sort(a+1,a+n+1,cmpp);
		zh=0;
		if(flag1==0&&flag2==0){
			for(int i=1;i<=n/2;i++)zh+=a[i].max1;
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(f[a[i].id1]+1<=qq){
				ans+=a[i].num1;
				f[a[i].id1]++;
			}
			else{
				int sum=ans;
				sum=sum-a[i-1].num1+a[i].num1+a[i-1].num2;
				if(sum>ans){
					ans=sum; 
					f[a[i-1].id2]++;
				}
				else if(f[a[i].id2]+1<=qq){
					ans+=a[i].num2;
					f[a[i].id2]++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}//Ren5Jie4Di4Ling5%
