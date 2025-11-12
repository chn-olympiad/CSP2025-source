#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node{
	int w,c;
};
Node v1[N],v2[N],v3[N];
int get_max(int a1,int a2,int a3){
	if(a1>=a2&&a1>=a3) return 1;
	if(a2>=a1&&a2>=a3) return 2;
	if(a3>=a1&&a3>=a2) return 3;
}
bool cmp(Node x,Node y){
	return x.c<y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	    int cnt1=0,cnt2=0,cnt3=0,ans=0;
		int n;
		cin>>n;
		int a[5];
		for(int i=1;i<=n;i++){
			cin>>a[1]>>a[2]>>a[3];
			int p=get_max(a[1],a[2],a[3]);
			sort(a+1,a+3+1);
			if(p==1){
				v1[++cnt1].w=a[3];
				ans+=a[3];
				v1[cnt1].c=(a[3]-a[2]);
			}
			if(p==2){
				v2[++cnt2].w=a[3];
				ans+=a[3];
				v2[cnt2].c=(a[3]-a[2]);
			}
			if(p==3){
				v3[++cnt3].w=a[3];
				ans+=a[3];
				v3[cnt3].c=(a[3]-a[2]);
			}
		}
		if(cnt1>n/2){
			sort(v1+1,v1+cnt1+1,cmp);
			int t=cnt1-n/2;
			for(int i=1;i<=t;i++){
				ans-=v1[i].c;
			}
		}
		if(cnt2>(n/2)){
			sort(v2+1,v2+cnt2+1,cmp);
			int t=cnt2-n/2;
			for(int i=1;i<=t;i++){
				ans-=v2[i].c;
			}
		}
		if(cnt3>n/2){
			sort(v3+1,v3+cnt3+1,cmp);
			int t=cnt3-n/2;
			for(int i=1;i<=t;i++){
				ans-=v3[i].c;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
//Ren5Jie4Di4Ling5%
