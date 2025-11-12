#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int num1,num2,num3;
int use[N];
struct node{
	int x,y,z;
	int cnt;
}a[N],b[N],c[N];
bool cmp(node w,node v){
	return w.x>v.x;
}
bool cmp1(node w,node v){
	return w.y>v.y;
}
bool cmp2(node w,node v){
	return w.z>v.z;
}
void apple(){
	long long ans=0;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=a[i].x;
	}
	cout<<ans<<endl;
	return;
}
void boy(){
	for(int i=1;i<=n;i++){
		b[i].x=a[i].x;
		b[i].y=a[i].y;
		b[i].z=a[i].z;
		b[i].cnt=a[i].cnt;
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp1);
	/*
	for(int i=1;i<=n;i++)cout<<a[i].x<<" "<<a[i].cnt<<endl;
	cout<<endl;
	cout<<endl;
	for(int i=1;i<=n;i++)cout<<b[i].y<<" "<<b[i].cnt<<endl;
	cout<<endl;
	*/
	long long ans1=0,ans2=0;
	int use1=0,use2=0;
	for(int i=1;i<=n;i++){
		if(a[i].cnt!=b[i].cnt){
			if(!use[a[i].cnt]&&use1<=n/2){
				//cout<<a[i].cnt<<" ";
				//cout<<"ans1="<<ans1<<"+"<<a[i].x<<"("<<a[i].cnt<<")"<<endl;
				ans1+=a[i].x;
				use[a[i].cnt]=1;
				use1++;
			}
			if(!use[b[i].cnt]&&use2<=n/2){
				//cout<<b[i].cnt<<" ";
				//cout<<"ans2="<<ans2<<"+"<<b[i].x<<"("<<b[i].cnt<<")"<<endl;
				ans2+=b[i].y;
				use[b[i].cnt]=1;
				use2++;
			}
			//cout<<a[i].cnt<<" "<<b[i].cnt<<endl;
		}
	}
	//cout<<ans1<<" "<<ans2<<endl;
	
	int pd=0;
	if(!pd){
		if(use1==n/2){
			for(int i=1;i<=n;i++){
				if(!use[b[i].cnt]){
					ans2+=b[i].y;
				}
			}
		}
		else if(use2==n/2){
			for(int i=1;i<=n;i++){
				if(!use[a[i].cnt]){
					ans1+=a[i].x;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(!use[a[i].cnt]){
					if(a[i].x>b[i].y&&!use[a[i].cnt]&&use1<=n/2){
						ans1+=a[i].x;
						use[a[i].cnt]=1;
						use1++;
					}
					if(a[i].x<b[i].y&&!use[b[i].cnt]&&use2<=n/2){
						ans2+=b[i].y;
						use[b[i].cnt]=1;
						use2++;
					}
				}
			}
		}
		pd=1;
		for(int i=1;i<=n;i++){
			if(use[a[i].cnt]!=1){
				pd=0;
				break;
			}
		}
	}
	cout<<ans1+ans2<<endl;
	return;
}
void cat(){
	int ans=0;
	int e;
	for(int i=1;i<=3;i++){
		if(i==1)e=a[1].x;
		if(i==2)e=a[1].y;
		if(i==3)e=a[1].z;
		for(int j=1;j<=3;j++){
			if(i!=j){
				if(j==1)ans=max(ans,e+a[2].x);
				if(j==2)ans=max(ans,e+a[2].y);
				if(j==3)ans=max(ans,e+a[2].z);
			}
		}
	}
	cout<<ans<<endl;
}
void Cat(){
	int ans=0;
	int e,r,t;
	int cnt;
	for(int i=1;i<=3;i++){
		if(i==1)e=a[1].x;
		if(i==2)e=a[1].y;
		if(i==3)e=a[1].z;
		for(int j=1;j<=3;j++){
			if(j==1)r=a[2].x;
			if(j==2)r=a[2].y;
			if(j==3)r=a[2].z;
			for(int k=1;k<=3;k++){
				if(k==3)t=a[3].x;
				if(k==3)t=a[3].y;
				if(k==3)t=a[3].z;
				for(int l=1;l<=3;k++){
					if(l==1)ans=max(ans,e+r+t+a[4].x);
					if(l==2)ans=max(ans,e+r+t+a[4].y);
					if(l==3)ans=max(ans,e+r+t+a[4].z);
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int y1=0,z1=0;
		memset(use,0,sizeof(use));
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].cnt=i;
			if(a[i].y==0)y1++;
			if(a[i].z==0)z1++;
		}
		num1=num2=num3;
		if(y1==n&&z1==n){
			apple();
		}
		else if(y1!=n&&z1==n){
			boy();
		}
		else if(n==2){
			cat();
		}
		else if(n==4){
			Cat();
		}
	}
	return 0;
}
/*Ren5Jie4Di4Ling5%*/
/*
1
4
1 2 0
3 4 0
3 1 0
6 4 0
*/
/*
2
10
5 6 0
5 4 0
3 2 0
5 4 0
1 3 0
1 1 0
2 3 0
2 4 0
2 1 0
1 0 0
10
5 6 0
5 4 0
3 2 0
5 4 0
1 3 0
1 1 0
2 3 0
2 4 0
2 1 0
1 0 0
*/

