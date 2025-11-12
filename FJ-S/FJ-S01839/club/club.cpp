#include<bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define of(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=110000;
int T;
int n;
struct qwq{
	int a1,a2,a3;
	int maxn,mid;
	int fmaxn,fmid;
}a[N];
int num[10];
bool cmp(qwq peo,qwq ple){
	return peo.fmaxn-peo.fmid>ple.fmaxn-ple.fmid;
}
struct qqq{
	int sum;
	int id;
}b[4];
bool cmp2(qqq q1,qqq q2){
	return q1.sum>q2.sum;
}
ll ans;
int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		num[1]=num[2]=num[3]=0;
		ans=0;
		fo(i,1,n){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			b[1]={a[i].a1,1};
			b[2]={a[i].a2,2};
			b[3]={a[i].a3,3};
			sort(b+1,b+1+3,cmp2);
			a[i].fmaxn=b[1].sum,a[i].maxn=b[1].id;
			a[i].fmid=b[2].sum,a[i].mid=b[2].id;
		}
		sort(a+1,a+1+n,cmp);
		fo(i,1,n){
			if(num[a[i].maxn]!=n/2){
				num[a[i].maxn]++;
				ans+=a[i].fmaxn;
			}
			else{
				num[a[i].mid]++;
				ans+=a[i].fmid;
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}
