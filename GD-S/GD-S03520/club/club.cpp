#include<bits/stdc++.h>
using namespace std;
int t,n,f[100005];
struct L{
	int x,y,z,id;
}a[100005],a1[100005],a2[100005],a3[100005];
bool cmp1(L p,L q){
	return p.y-p.x<q.y-q.x&&p.z-p.x<q.z-q.x;
}
bool cmp2(L p,L q){
	return p.z-p.y<q.z-q.y&&p.x-p.y<q.x-q.y;
}
bool cmp3(L p,L q){
	return p.y-p.z<q.y-q.z&&p.x-p.z<q.x-q.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(0));
		long long ans1=0,ans2=0,ans3=0;
		int cnt1=0,cnt2=0,cnt3=0;
		int f1=1,f2=1,f3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			f[i]=1,a[i].id=i;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++) a1[i]=a[i];
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++) a2[i]=a[i];
		sort(a+1,a+1+n,cmp3);
		for(int i=1;i<=n;i++) a3[i]=a[i];
		bool fff=1;
		while(fff){
			fff=0;
			while(f[a1[f1].id]==0&&f1<=n) f1++;
			while(f[a2[f2].id]==0&&f2<=n) f2++;
			while(f[a3[f3].id]==0&&f3<=n) f3++;
			if(f1<=n&&cnt1<n/2&&a1[f1].x>=a2[f2].y&&a1[f1].x>=a3[f3].z){
				fff=1;
				cnt1++,ans1+=a1[f1].x; 
				f[a1[f1++].id]=0;
			}
			else if(f2<=n&&cnt2<n/2&&a2[f2].y>=a1[f1].x&&a2[f2].y>=a3[f3].z){
				fff=1;
				cnt2++,ans2+=a2[f2].y; 
				f[a2[f2++].id]=0;
			}
			else if(f3<=n&&cnt3<n/2&&a3[f3].z>=a1[f1].x&&a3[f3].z>=a2[f2].y){
				fff=1;
				cnt3++,ans3+=a3[f3].z; 
				f[a3[f3++].id]=0;
			}
		}
		cout<<ans1+ans2+ans3<<"\n";
	}
	return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
