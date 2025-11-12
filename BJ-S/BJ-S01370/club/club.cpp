#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	
	int a1,a2,a3;
	int dis;
	int id;
	
}a[N];
bool cmp1(node a,node b){
	return a.dis>b.dis;
}
int t,n,ans=0;
bool flagAB=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t; 
	for(int i=1;i<=t;i++){
		int mem1=0,mem2=0,mem3=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].dis=a[i].a1-a[i].a2;
			a[i].id=i;
			if(a[i].a3!=0)flagAB=0;
		}
		if(!flagAB){
			for(int i=1;i<=n;i++){
				if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3&&mem1<(n/2)){
						ans+=a[i].a1;
						mem1++;
				}
				else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3&&mem2<(n/2)){
					ans+=a[i].a2;
					mem2++;
				}
				else if(mem3<(n/2)){
					ans+=a[i].a3;
					mem3++;
				}
			
			}
			cout<<ans<<"\n";
		}
		else if(n==2){
			int p1=a[1].a1+a[2].a2,p2=a[1].a1+a[2].a3,p3=a[1].a2+a[2].a1; 
			int p4=a[1].a2+a[2].a3,p5=a[1].a3+a[2].a1,p6=a[1].a3+a[2].a2;
			ans=max(max(p1,p2),max(max(p3,p4),max(p5,p6)));
			cout<<ans<<"\n";
		}
		else{
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)ans+=a[i].a1;
			for(int i=n/2+1;i<=n;i++)ans+=a[i].a2;
			cout<<ans<<"\n";
		}
		
	}
	
	
	return 0;
}
