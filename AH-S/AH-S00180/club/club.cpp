#include<bits/stdc++.h>
using namespace std;
#define N 100010
int a1[N],a2[N],a3[N];
int c1,c2,c3,gap_,mode;
struct p{
	int num;
	int qu;
	int gap;
}q[N];
bool cmp(p a,p b){
	return a.gap<b.gap;
}
void init(){
	memset(a1,0,sizeof(a1));
	memset(a2,0,sizeof(a2));
	memset(a3,0,sizeof(a3));
	c1=0;c2=0;c3=0;
}
void fun(){
	init();
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a1[i]>>a2[i]>>a3[i];
		int sum=a1[i]+a2[i]+a3[i];
		int maxm=max(a1[i],max(a2[i],a3[i])),minm=min(a1[i],min(a2[i],a3[i]));
		int secmax=sum-maxm-minm;
		ans+=maxm;
		gap_=maxm-secmax;
		q[i].gap=gap_;q[i].num=i;
		if(a1[i]==maxm) q[i].qu=1,c1++;
		else if(a2[i]==maxm) q[i].qu=2,c2++;
		else if(a3[i]==maxm) q[i].qu=3,c3++;
	}
	int cntcut=0;
	if(c1>(n/2)) mode=1,cntcut=c1;
	else if(c2>(n/2)) mode=2,cntcut=c2;
	else if(c3>(n/2)) mode=3,cntcut=c3;
	cntcut-=(n/2);
	sort(q,q+n,cmp);
	for(int i=0,cnt=0;cnt<cntcut;i++){
		if(q[i].qu==mode){
			ans-=q[i].gap;
			cnt++;
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=0;ii<t;ii++)fun();
	return 0;
}
