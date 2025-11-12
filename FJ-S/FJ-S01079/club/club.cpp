#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
#define int long long
//注意：N大小   long long   freopen   程序名   文件夹名
//T1 :100
int _,n;
struct student{
	int l1,l2,l3,zhjds;	
}a[N];
struct club{
	int cnt,students[N];
}clas[7];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--){
		clas[1].cnt=clas[2].cnt=clas[3].cnt=0;
		cin>>n;
		int limit=n/2,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].l1>>a[i].l2>>a[i].l3;
			a[i].id=i;
			int now=max({a[i].l1,a[i].l2,a[i].l3});
			int f;
			if(now==a[i].l1)f=1,ans+=a[i].l1;
			else if(now==a[i].l2)f=2,ans+=a[i].l2;
			else if(now==a[i].l3)f=3,ans+=a[i].l3;
			clas[f].cnt++;
			clas[f].students[clas[f].cnt]=i;
		}//读入和统计最喜欢 的 和每个的人数 
		if(clas[1].cnt<=limit&&clas[2].cnt<=limit&&clas[3].cnt<=limit){
			cout<<ans<<"\n";
			continue;
		}
		if(clas[1].cnt>limit){
			int f[N];memset(f,0,sizeof f);
			
			for(int i=1;i<=clas[1].cnt;i++){
				f[i]=min(a[clas[1].students[i]].l1-a[clas[1].students[i]].l2 , a[clas[1].students[i]].l1-a[clas[1].students[i]].l3);
			}
			sort(f+1,f+clas[1].cnt+1);
			for(int i=1;i<=(clas[1].cnt-limit);i++){
				ans-=f[i];
			}
			cout<<ans<<"\n";
			
			continue;
		}if(clas[2].cnt>limit){
			int f[N];memset(f,0,sizeof f);
			
			for(int i=1;i<=clas[2].cnt;i++){
				f[i]=min(a[clas[2].students[i]].l2-a[clas[2].students[i]].l1 , a[clas[2].students[i]].l2-a[clas[2].students[i]].l3);
			}
			sort(f+1,f+clas[2].cnt+1);
			for(int i=1;i<=(clas[2].cnt-limit);i++){
				ans-=f[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		else{
			int f[N];memset(f,0,sizeof f);
			
			for(int i=1;i<=clas[3].cnt;i++){
				f[i]=min(a[clas[3].students[i]].l3-a[clas[3].students[i]].l1 , a[clas[3].students[i]].l3-a[clas[3].students[i]].l2);
			}
			sort(f+1,f+clas[3].cnt+1);
			for(int i=1;i<=(clas[3].cnt-limit);i++){
				ans-=f[i];
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
/*  u_u  */
