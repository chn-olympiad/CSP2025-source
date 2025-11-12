#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct stu{
	int d1,d2,d3,sumi,l;
} a[100010];;
int n;
bool cmp(stu x,stu y){
	return x.sumi>y.sumi;
}
bool cmp1(stu x,stu y){
	return x.d1>y.d1;
}
int max(int x,int y){
	if(x>y) return x;
	return y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long ans=0;
		cin>>n;//max(max(a[i-1].d1+a[i].d2,max(a[i-1].d1+a[i].d3,a[i-1].d2+a[i].d3))
		bool f=1;
		int ra=n/2,rb=n/2,rc=n/2;		
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			if(a[i].d3!=0&&a[i].d2!=0) f=0;
			if(i%2==0){
				a[i].sumi=max(a[i].d1+a[i-1].d2,a[i].d1+a[i-1].d3);
				a[i].sumi=max(a[i].sumi,max(a[i].d2+a[i-1].d1,a[i].d2+a[i-1].d3));
				a[i].sumi=max(a[i].sumi,max(a[i].d3+a[i-1].d1,a[i].d3+a[i-1].d2));
			}
		}
		if(f){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].d1;
			}
			cout<<ans;
			return 0;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<n;i++) ans+=a[i].sumi;
		cout<<ans<<endl;
		for(int i=1;i<n-1;i++){
			a[i].d1=a[i].d2=a[i].d3=a[i].sumi=0;
		}
	}
	return 0;
}
