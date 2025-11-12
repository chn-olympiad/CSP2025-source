#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
struct p{
	int id,v;
};
int t;
int n;
p a1[MAXN],a2[MAXN],a3[MAXN];
p c1[MAXN],c2[MAXN],c3[MAXN];
int mx,mn;
int mns[MAXN][3];
int ans;
int np1,np2,np3;
int join[MAXN];
//c1,c2,c3表示假设每个部门都选n/2个人那么在不考虑重复选人的情况下的最佳方案
bool grt(p b,p d){
	return b.v>d.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		ans=0,np1=0,np2=0,np3=0;
		cin>>n;
		for(int j=1;j<=n;++j){
			cin>>a1[j].v>>a2[j].v>>a3[j].v;
			a1[j].id=j,a2[j].id=j,a3[j].id=j;
		}
		for(int j=1;j<=n;++j){
			mx=max(a1[j].v,max(a2[j].v,a3[j].v));
			mns[j][0]=mx-a1[j].v;
			mns[j][1]=mx-a2[j].v;
			mns[j][2]=mx-a3[j].v;
			if(a1[j].v>a2[j].v&&a1[j].v>a3[j].v){
				++np1;
				join[j]=1;
			}else if(a2[j].v>a1[j].v&&a2[j].v>a3[j].v){
				++np2;
				join[j]=2;
			}else{
				++np3;
				join[j]=3;
			}
			ans+=mx;
//			cout<<mx<<' ';
		}
//		cout<<'\n';
		for(int j=1;j<=n;++j){
//			cout<<join[j]<<' ';
		}
//		cout<<'\n';
		for(int j=1;j<=n;++j){
			for(int k=0;k<3;++k){
//				cout<<mns[j][k]<<' ';
			}
//			cout<<'\n';
		}
//		cout<<np1<<' '<<np2<<' '<<np3<<'\n';
		while(np1>n/2){
			mn=2147483647;
			for(int j=1;j<=n;++j){
				if(join[j]==1){
					mn=min(mn,min(mns[j][1],mns[j][2]));
					--np1;
					if(mns[j][1]<mns[j][2]){
						join[j]=2;
//						++np2;
					}else{
						join[j]=3;
//						++np3;
					}
				}
			}
			ans-=mn;
//			cout<<mn<<' ';
		}
		while(np2>n/2){
			mn=2147483647;
			for(int j=1;j<=n;++j){
				if(join[j]==2){
					mn=min(mn,min(mns[j][0],mns[j][2]));
					--np2;
					if(mns[j][0]<mns[j][2]){
						join[j]=1;
//						++np1;
					}else{
						join[j]=3;
//						++np3;
					}
					break;
				}
			}
			ans-=mn;
//			cout<<mn<<' ';
//			cout<<ans<<' ';
		}
//		cout<<ans;
		while(np3>n/2){
			mn=2147483647;
			for(int j=1;j<=n;++j){
				if(join[j]==3){
					mn=min(mn,min(mns[j][0],mns[j][1]));
					--np2;
					if(mns[j][0]<mns[j][1]){
						join[j]=1;
//						++np1;
					}else{
						join[j]=2;
//						++np2;
					}
				}
			}
			ans-=mn;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/