#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][3],n;
int b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans=0,cnt0=0,cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				ans+=a[i][0];
				cnt0++;
			}
			else{
				if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
					ans+=a[i][1];
					cnt1++;
				} 
				else{
					ans+=a[i][2];
					cnt2++;
				}
			}
		}
//		cerr<<cnt0<<" "<<cnt1<<" "<<cnt2<<endl;
		int m=n>>1;
		if(cnt0<=m&&cnt1<=m&&cnt2<=m){
//			cout<<"!!!"<<endl;
			printf("%d\n",ans);
			continue;
		}
		int p=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				if(cnt0>m){
					b[++p]=a[i][0]-max(a[i][1],a[i][2]);
				}
			}
			else{
				if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
					if(cnt1>m){
						b[++p]=a[i][1]-max(a[i][0],a[i][2]);
					}
				} 
				else{
					if(cnt2>m){
						b[++p]=a[i][2]-max(a[i][0],a[i][1]);
					}
				}
			}
		}
		sort(b+1,b+1+p);
		for(int i=1;i+m<=p;i++){
			ans-=b[i];
		}
		printf("%d\n",ans);
	}
	
	return 0;
} 
/*
1
4
1 3 2 
1 3 2
1 3 2
2 3 2 
*/
