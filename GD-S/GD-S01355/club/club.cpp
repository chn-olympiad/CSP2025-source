#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct node{
	int a1;
	int a2;
	int a3;
};
node a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		node sum={0,0,0};
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			int sp=-1,ii=0;
			if(a[i].a1>sp){
				sp=a[i].a1;ii=1;
			}
			if(a[i].a2>sp){
				sp=a[i].a2;ii=2;
			}
			if(a[i].a3>sp){
				sp=a[i].a3;ii=3;
			}
			if(ii==1){
				if(sum.a1<=(n/2)){ans+=sp;sum.a1++;}
				else if(sum.a2>sum.a3){
					ans+=a[i].a3;sum.a3++;
				}
				else ans+=a[i].a2;sum.a2++;
			}
			if(ii==2){
				if(sum.a2<=(n/2)){ans+=sp;sum.a2++;}
				else if(sum.a1>sum.a3){
					ans+=a[i].a3;sum.a3++;
				}
				else ans+=a[i].a1;sum.a1++;
			}
			if(ii==3){
				if(sum.a3<=(n/2)){ans+=sp;sum.a3++;}
				else if(sum.a1>sum.a2){
					ans+=a[i].a2;sum.a2++;
				}
				else ans+=a[i].a1;sum.a1++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
