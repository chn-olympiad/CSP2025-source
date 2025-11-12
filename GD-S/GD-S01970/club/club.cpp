/*
退役快乐
一题没A
下辈子再打OI吧
我真是fvv
挺后悔自己去年没缴费的 
去年的题刚好我都擅长
再见啦信竞的同学们
*/ 
//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define ll long long
#define f(a,b,c) for(int a=b;a<=c;a++)
#define d(a,b,c) for(int a=b;a>=c;a--)
using namespace std;
const int N=1e5+5;
struct node{
	int x,y,z;
}a[N];
ll ans;
int T,n,x,y,z;
bool cmp(node a,node b){
	return a.x>b.y;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n,ans=0;
		f(i,1,n)cin>>x>>y>>z,a[i]={x,y,z};
		sort(a+1,a+n+1,cmp);
		f(i,1,n/2)ans+=a[i].x;
		cout<<ans<<"\n";
	}
	return 0;
}
//#include<bits/stdc++.h>
//#define ll long long
//#define f(a,b,c) for(int a=b;a<=c;a++)
//#define d(a,b,c) for(int a=b;a>=c;a--)
//using namespace std;
//const int N=1e5+5;
//struct node{
//	int x,y,z,m,mid,s;
//}a[N];
//ll ans;
//int T,n,x,y,z,m,mid,cnt[4],yl[3][N];
//bool cmp(node a,node b){
////	if(a.s==b.s)return a.m>b.m;
////	return a.s>b.s;
//	return a.m>b.m;
//}
//bool cmp2(node a,node b){
////	if(a.s==b.s)return a.m>b.m;
////	return a.s>b.s;
//	return a.s<b.s;
//}
//int main(){
//	ios::sync_with_stdio(0),cin.tie(0);
////	freopen("club.in","r",stdin);
////	freopen("club.out","w",stdout);
//	cin>>T;
//	while(T--){
//		cin>>n,ans=0;
//		f(i,1,3)cnt[i]=0;
//		f(i,1,n){
//			cin>>a[i].x>>a[i].y>>a[i].z;
//			x=a[i].x,y=a[i].y,z=a[i].z;
//			a[i].m=max(x,max(y,z));
//			a[i].mid=(min(x,y)>z?min(x,y):min(x,z));
//			a[i].s=a[i].m-a[i].mid;
//		}
//		sort(a+1,a+n+1,cmp);
//		f(i,1,n){
//			x=a[i].x,y=a[i].y,z=a[i].z,m=a[i].m,mid=a[i].mid;
//			if(x==m){
////				cnt[1]++,ans+=x,yl[1][cnt[1]]=i;
//				if(cnt[1]<n/2)cnt[1]++,ans+=x;
//				else if(y==mid)cnt[2]++,ans+=y;
//				else if(z==mid)cnt[3]++,ans+=z;
//			}else if(y==m){
////				cnt[2]++,ans+=y,yl[2][cnt[2]]=i;
//				if(cnt[2]<n/2)cnt[2]++,ans+=y;
//				else if(x==mid)cnt[1]++,ans+=x;
//				else if(z==mid)cnt[3]++,ans+=z;
//			}else if(z==m){
////				cnt[3]++,ans+=z,yl[3][cnt[3]]=i;
//				if(cnt[3]<n/2)cnt[3]++,ans+=z;
//				else if(x==mid)cnt[1]++,ans+=x;
//				else if(y==mid)cnt[2]++,ans+=y;
//			}
//		}
//		if(max(cnt[1],max(cnt[2],cnt[3]))<=n/2){
//			cout<<ans<<"\n";
//		}else{
//			if(cnt[1]>n/2){
//				sort()
//			}else if(cnt[2]>n/2){
//				
//			}else if(cnt[3]>n/2){
//				
//			}
//		}
//	}
//	return 0;
//}
///*
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
//
//18
//4
//13
//*/
