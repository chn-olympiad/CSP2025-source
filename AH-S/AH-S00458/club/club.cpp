#include<bits/stdc++.h>
#define for1(i,a,b) for(int i = (a);(i) <= (b);++(i))
#define for2(i,a,b) for(int i = (a);(i) >= (b);--(i))
#define pb push_back
#define pf push_front
using namespace std;
template<typename T> T cmax(T &x,T y){if(x < y) x = y;}
template<typename T> T cmin(T &x,T y){if(x > y) x = y;}
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e5 + 5;
const int M = 1e5 + 5;
const int MOD = 10007;
int n;
struct node{
	int t1,t2,t3;
}a[N];
int q1[N],q2[N],q3[N];
int tmp1,tmp2,tmp3;
LL ans;
void solve(){
	cin>>n; ans=tmp1=tmp2=tmp3=0;
	for1(i,1,n) {
		cin>>a[i].t1>>a[i].t2>>a[i].t3;
//		cout<<a[i].t1<<" "<<a[i].t2<<" "<<a[i].t3<<"\n";
		if(a[i].t1>=a[i].t2&&a[i].t1>=a[i].t3){
			q1[++tmp1]=i;
			ans+=a[i].t1;
		}else if(a[i].t2>=a[i].t1&&a[i].t2>=a[i].t3){
			q2[++tmp2]=i;
			ans+=a[i].t2;
		}else{
			q3[++tmp3]=i;
			ans+=a[i].t3;
		}
	}/*
	cout<<ans<<"\n";
	cout<<"t1:"<<tmp1<<" ";
	for1(i,1,tmp1) cout<<q1[i]<<" "; cout<<"\n";
	cout<<"t2:"<<tmp2<<" ";
	for1(i,1,tmp2) cout<<q2[i]<<" "; cout<<"\n";
	cout<<"t3:"<<tmp3<<" ";
	for1(i,1,tmp3) cout<<q3[i]<<" "; cout<<"\n";*/
	if(tmp1>n/2){
		for1(i,1,tmp1) q1[i]=min(a[q1[i]].t1-a[q1[i]].t2,a[q1[i]].t1-a[q1[i]].t3);
		sort(q1+1,q1+1+tmp1);
		for1(i,1,tmp1-(n/2)) {
		    //cout<<q1[i]<<"\n";
		    ans-=q1[i];
		}
	}else if(tmp2>n/2){
		for1(i,1,tmp2) q2[i]=min(a[q2[i]].t2-a[q2[i]].t1,a[q2[i]].t2-a[q1[i]].t3);
		sort(q2+1,q2+1+tmp2);
		for1(i,1,tmp2-(n/2)) ans-=q2[i];
	}else if(tmp3>n/2){
		for1(i,1,tmp3) q3[i]=min(a[q3[i]].t3-a[q3[i]].t2,a[q3[i]].t3-a[q3[i]].t1);
		//for1(i,1,tmp3) cout<<q3[i]<<" "; cout<<"\n";
		sort(q3+1,q3+1+tmp3);
		for1(i,1,tmp3-(n/2)) {
		    //cout<<q3[i]<<"\n";
		    ans-=q3[i];
		}
	}
	cout<<ans<<"\n";
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
int testcase=1;
cin>>testcase;
while(testcase--){
	solve();
}
    return 0;
}
