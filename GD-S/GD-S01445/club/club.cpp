#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
//bool _1;
namespace zyh{
	struct ccf{
		int pos,val,op;
	}xld[N<<1];
	bool cmp(ccf pre,ccf nxt){
		return pre.val>nxt.val;
	}
	bool vst[N];
	int t,n,ans,cnt2,cnt3,maxn;
//	int f[205][205][205];
	void work(){
//		memset(f,0x80,sizeof(f));
//		f[0][0][0]=0;
		cin>>n;
		ans=cnt2=cnt3=maxn=0;
//		bool flag=(n<=200);
		for(int i=1;i<=n;i++){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			ans+=a1;
			xld[2*i]={i,a2-a1,2},xld[2*i-1]={i,a3-a1,3};
			vst[i]=0;
//			if(!flag) continue;
//			for(int j=0;j<=min(n/2,i);j++){
//				for(int k=0;k<=min(n/2,i-j);k++){
//					f[i][j][k]=f[i-1][j][k]+a1;
//					if(j>0) f[i][j][k]=max(f[i-1][j-1][k]+a2,f[i][j][k]);
//					if(k>0) f[i][j][k]=max(f[i-1][j][k-1]+a3,f[i][j][k]);
//				}
//			}
		}
//		if(flag){
//			for(int j=0;j<=n/2;j++){
//				for(int k=0;k<=min(n/2,n-j);k++){
//					maxn=max(maxn,f[n][j][k]);
//				}
//			}
//			cout<<maxn<<'\n';
//			return;
//		}
		sort(xld+1,xld+2*n+1,cmp);
//		cout<<ans<<' '<<maxn<<'\n';
//		for(int i=1;i<=2*n;i++){
//			cout<<xld[i].pos<<' '<<xld[i].val<<' '<<xld[i].op<<'\n';
//		}
//		cout<<"selected:\n";
		for(int i=1;i<=2*n;i++){
			if(xld[i].val<0&&cnt2+cnt3>=n/2) break;
			if(vst[xld[i].pos]||(xld[i].op==2&&cnt2>=n/2)||(xld[i].op==3&&cnt3>=n/2)) continue;
			if(xld[i].op==2) cnt2++;
			else cnt3++;
			ans+=xld[i].val;
//			cout<<xld[i].pos<<' '<<xld[i].val<<' '<<xld[i].op<<'\n';
			vst[xld[i].pos]=1;
		}
//		cout<<'\n';
//		cout<<cnt2<<' '<<cnt3<<'\n';
		cout<<ans<<'\n';
	}	
	signed lqr(){
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>t;
		while(t--) work();
		return 0;
	}
}
void file_io(string str){
	string s1=str+".in",s2=str+".out";
	freopen(s1.c_str(),"r",stdin);
	freopen(s2.c_str(),"w",stdout);
}
//bool _2;
signed main(){
	file_io("club");
//	cerr<<(&_1-&_2)/1024.0/1024;
	return zyh::lqr();
}
