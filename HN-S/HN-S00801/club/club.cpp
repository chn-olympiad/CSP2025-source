#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,t,flagA,cnt[10];
struct node{
	int a1,a2,a3,c1,c2,maid,miid;
}a[N];
int query(int x,int id){
	if(x==1){
		return a[id].a1;
	}else if(x==2){
		return a[id].a2;
	}else{
		return a[id].a3;
	}
}
bool cmp(node x,node y){
	return x.a1>y.a1;
}
bool cmp1(node x,node y){
	if(x.c1==y.c1)return x.c2>y.c2;
	return x.c1>y.c1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		int ans=0;
		flagA=true;
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>=a[i].a2&&a[i].a2>=a[i].a3){
				a[i].maid=1;
				a[i].miid=3;
				a[i].c1=a[i].a1-a[i].a2;
				a[i].c2=a[i].a1-a[i].a3;
			}else if(a[i].a1>=a[i].a3&&a[i].a3>=a[i].a2){
				a[i].maid=1,a[i].miid=2;
				a[i].c1=a[i].a1-a[i].a3;
				a[i].c2=a[i].a1-a[i].a2;
			}else if(a[i].a2>=a[i].a1&&a[i].a1>=a[i].a3){
				a[i].maid=2,a[i].miid=3;
				a[i].c1=a[i].a2-a[i].a1;
				a[i].c2=a[i].a2-a[i].a3;
			}else if(a[i].a2>=a[i].a3&&a[i].a3>=a[i].a1){
				a[i].maid=2,a[i].miid=1;
				a[i].c1=a[i].a2-a[i].a3;
				a[i].c2=a[i].a2-a[i].a1;
			}else if(a[i].a3>=a[i].a1&&a[i].a1>=a[i].a2){
				a[i].maid=3,a[i].miid=2;
				a[i].c1=a[i].a3-a[i].a1;
				a[i].c2=a[i].a3-a[i].a2;
			}else if(a[i].a3>=a[i].a2&&a[i].a2>=a[i].a1){
				a[i].maid=3,a[i].miid=1;
				a[i].c1=a[i].a3-a[i].a2;
				a[i].c2=a[i].a3-a[i].a1;
			}
			if(a[i].a2!=0||a[i].a3!=0)flagA=false;
		}
		if(flagA){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
			}
			cout<<ans<<'\n';
			continue ;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(cnt[a[i].maid]==n/2){
				if(cnt[6-a[i].maid-a[i].miid]==n/2){
					ans+=query(a[i].miid,i);
					cnt[a[i].miid]++;
				}else{
					ans+=query(6-a[i].maid-a[i].miid,i);
					cnt[6-a[i].maid-a[i].miid]++;
				}
			}else{
				ans+=query(a[i].maid,i);
				cnt[a[i].maid]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
