#include <bits/stdc++.h>
using namespace std;

struct edge{
	int a[4];
}v[100005];

int t,n;
int A[100005],B[100005],C[100005];

int chkmax(int i){
	if(v[i].a[1]>=v[i].a[2]&&v[i].a[1]>=v[i].a[3]) return 1;
	else if(v[i].a[2]>=v[i].a[1]&&v[i].a[2]>=v[i].a[3]) return 2;
	else if(v[i].a[3]>=v[i].a[1]&&v[i].a[3]>=v[i].a[2]) return 3;	
}

bool cmp1(int i,int j){
	return min(v[i].a[1]-v[i].a[2],v[i].a[1]-v[i].a[3])<min(v[j].a[1]-v[j].a[2],v[j].a[1]-v[j].a[3]);
}
bool cmp2(int i,int j){
	return min(v[i].a[2]-v[i].a[1],v[i].a[2]-v[i].a[3])<min(v[j].a[2]-v[j].a[1],v[j].a[2]-v[j].a[3]);
}
bool cmp3(int i,int j){
	return min(v[i].a[3]-v[i].a[1],v[i].a[3]-v[i].a[2])<min(v[j].a[3]-v[j].a[1],v[j].a[3]-v[j].a[2]);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1; i<=n; i++) cin>>v[i].a[1]>>v[i].a[2]>>v[i].a[3];
		int cnt1=0,cnt2=0,cnt3=0;
		memset(A,0,sizeof A),memset(B,0,sizeof B),memset(C,0,sizeof C);
		for(int i = 1; i<=n; i++){
			int j=chkmax(i);
			if(j==1) A[++cnt1]=i;
			else if(j==2) B[++cnt2]=i;
			else if(j==3) C[++cnt3]=i;
		}
		long long ans=0;
		for(int i = 1; i<=n; i++){
			int j=chkmax(i);
			if(j==1) ans+=v[i].a[1];
			else if(j==2) ans+=v[i].a[2];
			else if(j==3) ans+=v[i].a[3];
		}
		if(cnt1>n/2){
			sort(A+1,A+1+cnt1,cmp1);
			for(int j = 1; j<=cnt1-n/2; j++){
				if(v[A[j]].a[3]>v[A[j]].a[2]) ans+=(v[A[j]].a[3]-v[A[j]].a[1]);
				else ans+=(v[A[j]].a[2]-v[A[j]].a[1]);
			}
		}else if(cnt2>n/2){
			sort(B+1,B+1+cnt2,cmp2);
			for(int j = 1; j<=cnt2-n/2; j++){
				if(v[B[j]].a[1]>v[B[j]].a[3]) ans+=(v[B[j]].a[1]-v[B[j]].a[2]);
				else ans+=(v[B[j]].a[3]-v[B[j]].a[2]);
			}
		}else if(cnt3>n/2){
			sort(C+1,C+1+cnt3,cmp3);
			for(int j = 1; j<=cnt3-n/2; j++){
				if(v[C[j]].a[1]>v[C[j]].a[2]) ans+=(v[C[j]].a[1]-v[C[j]].a[3]);
				else ans+=(v[C[j]].a[2]-v[C[j]].a[3]);
			}
		}
		cout<<ans<<'\n';
	}	
	return 0;
}
