#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
using ll=long long;
int n,m;
int cur[maxn];

struct Node{
	int a1,a2,a3,x1,x2;
}a[maxn];

bool cmp(Node a,Node b){
	if(a.x1>=b.x1)a.x2<b.x2;
	return a.x1<b.x1;
//	if(a.a1==b.a1){
//		if(a.a2==b.a2)return a.a3>b.a3;
//		return a.a2>b.a2;
//	}
//	return a.a1>b.a1;
}

bool cmp1(Node a,Node b){
	return a.a1>b.a1;
}
void solve1(){
	int ans=0;
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n/2;i++){
		ans+=a[i].a1;
	}
	cout<<ans<<endl;
}
bool cmp2(Node a,Node b){
	return a.x1<b.x1;
}
void solve2(){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i].a1;
		a[i].x1=a[i].a1-a[i].a2;
	}
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n/2;i++){
		ans-=a[i].x1;
	}
	cout<<ans<<endl;
}

bool cmpa3(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}

void solve3(){
	int ca=n,cb=0,cc=0;
	int ans=0;
	pair<int,int> ax1[maxn],ax2[maxn];
	int idx[maxn];
	memset(idx,1,sizeof(idx));
	for(int i=1;i<=n;i++){
		ans+=a[i].a1;
		ax1[i].first=i;ax2[i].first=i;
		ax1[i].second=a[i].a1-a[i].a2;
		ax2[i].second=a[i].a1-a[i].a3;
	}
	sort(ax1+1,ax1+1+n,cmpa3);
	sort(ax2+1,ax2+1+n,cmpa3);
//	for(int i=1;i<=n;i++){
//		cout<<ax1[i].first<<" "<<ax1[i].second<<" "<<ax2[i].first<<" "<<ax2[i].second<<endl;
//	}
//	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		if(ca>m){
			if(cb+1<=m&&cc+1<=m&&ca-2>=0&&ax1[i].first != ax2[i].first){
				ans-=ax1[i].second;
				ans-=ax2[i].second;
				cc++,cb++,ca-=2;
				idx[ax1[i].first]=2;
				idx[ax2[i].first]=3;
			}else{
				if(cb+1<=m&&cc+1<=m&&ax1[i].second < ax2[i].second && ca-1>=0){
					cb++;ca--;idx[ax1[i].first]=2;
					ans-=ax1[i].second;
				}else if(cb+1<=m&&cc+1<=m&&ca-1>=0){
					cc++;ca--;idx[ax2[i].first]=3;
					ans-=ax2[i].second;
				}
			}
		}else break;
	}
//	cout<<ca<<" "<<cb<<" "<<cc<<endl;
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;m=n/2;
		int cntc=0,cntb=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a3==0)cntc++;
			if(a[i].a2==0)cntb++;
		}
		if(cntc==n && cntb==n){
			solve1();continue;
		}else if(cntc==n){
			solve2();continue;
		}else{
			solve3();continue;
		} 
//		int sum1=0,sum2=0,sum3=0,sum=0;
//		
//		int ca=0,cb=0,cc=0;
//		for(int i=1;i<=n;i++){
//			int x=max(a[i].a1,max(a[i].a2,a[i].a3));
//			if(x==a[i].a1)ca++,cur[i]=1;
//			else if(x==a[i].a2)cb++,cur[i]=2;
//			else cc++,cur[i]=3;
//			sum+=x;
//		}
//		if(ca<=m && cb<=m && cc<=m){
//			cout<<sum<<endl;
//			continue;
//		}
////		sort(a+1,a+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			if(cur[i]==1){
//				a[i].x1=a[i].a1-a[i].a2;
//				a[i].x2=a[i].a1-a[i].a3;
//			}
//			if(cur[i]==2){
//				a[i].x1=a[i].a2-a[i].a1;
//				a[i].x2=a[i].a2-a[i].a3;
//			}
//			if(cur[i]==3){
//				a[i].x1=a[i].a3-a[i].a2;
//				a[i].x2=a[i].a3-a[i].a1;
//			}
////			cout<<cur[i]<<" ";
////			cout<<a[i].x1<<" "<<a[i].x2<<endl;
//		}
//		sort(a+1,a+1+n,cmp);
//		int j=1;
//		while(ca>m || cb>m ||cc>m){
//			if(cur[j]==1 && ca>m){
////				cout<<"1.";
//				ca--;
//				if(a[j].x1<a[j].x2)cb++,sum-=a[j].x1;
//				else cc++,sum-=a[j].x2;
//			}else if(cur[j]==2 && cb>m){
////				cout<<"2.";
//				cb--;
//				if(a[j].x1<a[j].x2)ca++,sum-=a[j].x1;
//				else cc++,sum-=a[j].x2;
//			}else if(cur[j]==3 && cc>m){
////				cout<<"3.";
//				cc--;
//				if(a[j].x1<a[j].x2)cb++,sum-=a[j].x1;
//				else ca++,sum-=a[j].x2;
//			}
//		}
//		cout<<sum<<endl;
//		sort(a+1,a+1+n,cmp1);
//		for(int i=1;i<=m;i++){
//			sum1+=a[i].a1;
//		}
//		for(int i=m+1;i<=n;i++){
//			sum1+=max(a[i].a2,a[i].a3);
//		}
////		cout<<sum1<<endl;
//		
//		sort(a+1,a+1+n,cmp2);
//		for(int i=1;i<=m;i++){
//			sum2+=a[i].a2;
//		}
//		for(int i=m+1;i<=n;i++){
//			sum2+=max(a[i].a1,a[i].a3);
//		}
////		cout<<sum2<<endl;
//		
//		sort(a+1,a+1+n,cmp3);
//		for(int i=1;i<=m;i++){
//			sum3+=a[i].a3;
//		}
//		for(int i=m+1;i<=n;i++){
//			sum3+=max(a[i].a1,a[i].a2);
//		}
////		cout<<sum3<<endl;
//		cout<<max(sum1,max(sum2,sum3))<<endl;
	}
	return 0;
}
/*
147325
125440
152929
150176
158541

1
6
3 2 1
6 4 0
8 7 6
9 0 2
4 2 1
*/
