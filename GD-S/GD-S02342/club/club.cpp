#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e5+10;
int t,a[N][4],num[4],cnt,ans;
bool u[N];
struct node{
	int gr,v,per;
}b[N];
bool cmp(node x,node y){
	return x.v>y.v;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>t;
	while(t--){
		int mi1=0,mi2=0,mi3=0,m1=0,m2=0,m3=0;
		int n;
		ans=0,cnt=0;
		cin>>n;
		int k=n/2;
		num[1]=num[2]=num[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			u[i]=0;
			b[++cnt].gr=1,b[cnt].v=a[i][1],b[cnt].per=i;
			b[++cnt].gr=2,b[cnt].v=a[i][2],b[cnt].per=i;
			b[++cnt].gr=3,b[cnt].v=a[i][3],b[cnt].per=i;
		}
		sort(b+1,b+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			if(u[b[i].per]) continue;
			u[b[i].per]=1;
			if(num[b[i].gr]<k){
				if(b[i].gr==1) mi1=b[i].per,m1=b[i].v;//mi为最小的人，m为值 
				else if(b[i].gr==2) mi2=b[i].per,m2=b[i].v;
				else mi3=b[i].per,m3=b[i].v;
				num[b[i].gr]++;
				ans+=b[i].v;
			}else{
				int x=b[i].gr,xx,yy,w,X,V;
				if(x==1) xx=2,yy=3,w=mi1,V=m1;
				else if(x==2) xx=1,yy=3,w=mi2,V=m2;
				else xx=1,yy=2,w=mi3,V=m3;
				if(a[w][xx]>a[w][yy]) X=xx;
				else X=yy;
				if(V<b[i].v+a[w][X]){
					if(x==1){
						mi1=b[i].per,m1=b[i].v;
					}
					if(x==2){
						mi2=b[i].per,m2=b[i].v;
					}
					if(x==3){
						mi3=b[i].per,m3=b[i].v;
					}   
					ans=ans-V+b[i].v+a[w][X];
				} 
			} 
		}
		cout<<ans<<endl; 
	} 
	return 0;
}
/*
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
