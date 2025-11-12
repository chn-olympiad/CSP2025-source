#include<bits/stdc++.h>
using namespace std;
struct myd{
	int a1;
	int a2;
	int a3;
	int bj=0;
} a[100010];
int t,n;
bool cmp1(myd a,myd b){
	return a.a1 >b.a1 ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n;
		bool flagA=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0||a[i].a3!=0) flagA=0;
		}
		if(n==2) {
			int p1=max(a[1].a1 +a[2].a2,a[1].a1 +a[2].a3);
			int p2=max(a[1].a2+a[2].a1 ,a[1].a2 +a[2].a3);
			int p3=max(a[1].a3+a[2].a1 ,a[1].a3+a[2].a2);
			cout<<max(p1,max(p2,p3))<<endl;
			continue;
		}
		if(flagA){
			sort(a+1,a+n+1,cmp1);
			int d=n/2,js=0;
			for(int i=1;i<=d;i++){
				js+=a[i].a1; 
			}
			cout<<js<<endl;
			continue;
		}
		
	}













	return 0;
}


