#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,m;
long long ans;
int a1[N],a2[N],a3[N];
bool A=1,B=1;
int a[N][3];
bool vis[N];
int cnt1,cnt2,cnt3;
bool cmp(int a,int b){
	return a>b;
}
struct aaa{
	int a1,a2;
}bb[N];
bool cmp1(aaa a,aaa b){
	if(a.a1!=b.a1) return a.a1>b.a1;
	return a.a2>b.a2;
}
bool cmp2(aaa a,aaa b){
	if(a.a2!=b.a2) return a.a2>b.a2;
	return a.a1>b.a1;
}
bool cmp3(aaa a,aaa b){
	return max(a.a1,a.a2)>max(b.a1,b.a2);
}
void ff(int s,int c1,int c2,int c3,long long x){
	if(c1+c2+c3==n){
		ans=max(ans,x);
		return;
	}
	if(c1<m) ff(s+1,c1+1,c2,c3,x+a1[s]);
	if(c2<m) ff(s+1,c1,c2+1,c3,x+a2[s]);
	if(c3<m) ff(s+1,c1,c2,c3+1,x+a3[s]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;A=1;B=1;
		cnt1=cnt2=cnt3=0;
		cin>>n; m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0||a3[i]!=0)A=0;
			if(a3[i]!=0)B=0;
		}
		if(A){
			sort(a1+1,a1+1+n,cmp);
			for(int i=1;i<=m;i++){
				ans+=a1[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(B){
			for(int i=1;i<=n;i++){
				bb[i].a1=a1[i];
				bb[i].a2=a2[i];
			}
			int cc1=0,cc2=0;
			long long cnt1=0,cnt2=0,cnt3=0;
			sort(bb+1,bb+1+n,cmp3);
			for(int i=1;i<=n;i++){
				if(bb[i].a1>bb[i].a2&&cc1<m){
					cc1++;
					cnt3+=bb[i].a1;
				}else if(cc2<m){
					cc2++;
					cnt3+=bb[i].a2;
				}
			}
			ans=cnt3;
			sort(bb+1,bb+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(i<=m)cnt1+=bb[i].a1;
				else if(i-m<=m)cnt1+=bb[i].a2;
			}
			sort(bb+1,bb+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(i<=m)cnt2+=bb[i].a2;
				else if(i-m<=m)cnt2+=bb[i].a1;
			}
			ans=max(ans,max(cnt1,cnt2));
			cout<<ans<<endl;
			continue;
		}
		ff(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
