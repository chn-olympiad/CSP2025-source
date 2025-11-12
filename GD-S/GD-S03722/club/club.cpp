#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c;
	int maxans,idx; 
};
node a[10001];
bool cmp(node a,node b){
	return a.maxans>b.maxans;
}
int ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].maxans=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].maxans==a[i].a) a[i].idx=1;
			else if(a[i].maxans==a[i].b) a[i].idx=2;
			else a[i].idx=3;
		}
		sort(a+1,a+n+1,cmp);
		int sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++){
			int pos=a[i].idx;
			switch(pos){
				case 1:{
					if(sum1<n/2){
						ans+=a[i].maxans;
						sum1++;
					}else{
						if(a[i].b>a[i].c){
							sum2++;
							ans+=a[i].b;
						}else if(a[i].b==a[i].c){
							if(sum2<=sum3) sum2++,ans+=a[i].b;
							else sum3++,ans+=a[i].c;
						}else{
							sum3++;
							ans+=a[i].c;
						}
					}
					break;
				}
				case 2:{
					if(sum2<n/2){
						ans+=a[i].maxans;
						sum2++;
					}else{
						if(a[i].a>a[i].c){
							sum1++;
							ans+=a[i].a;
						}else if(a[i].a==a[i].c){
							if(sum1<=sum3) sum1++,ans+=a[i].a;
							else sum3++,ans+=a[i].c;
						}else{
							sum3++;
							ans+=a[i].c;
						}
					}
					break;
				}
				case 3:{
					if(sum3<n/2){
						ans+=a[i].maxans;
						sum3++;
					}else{
						if(a[i].a>a[i].b){
							sum1++;
							ans+=a[i].a;
						}else if(a[i].a==a[i].b){
							if(sum1<=sum2) sum1++,ans+=a[i].a;
							else sum2++,ans+=a[i].b;
						}else{
							sum2++;
							ans+=a[i].b;
						}
					}
					break;
				}
			}
			 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
