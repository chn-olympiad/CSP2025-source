#include "bits/stdc++.h"
using namespace std;

struct f{int b[4];}a[100010];

int x[4],ans,m,num;

bool cmp(f x,f y){
	return x.b[(m+2)%3]<y.b[(m+2)%3];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(x,0,sizeof(x));
		ans=0,num=0,m=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i].b[0]>>a[i].b[1]>>a[i].b[2];
			num=max(a[i].b[0],max(a[i].b[1],a[i].b[2]));
			ans+=num;
			for(int j=0;j<3;j++){
				if(num==a[i].b[j]){
					x[j]++;
					break;
				}
			}
		}
		
		num=max(x[0],max(x[1],x[2]));
		if(num<n/2) {
			cout<<ans<<endl;
			continue;
		}
		
		for(int i=0;i<3;i++)
			if(num==x[i]){
				m=i;
				break;
			}
			
		for(int i=1;i<=n;i++){
			a[i].b[(m+1)%3]=max(a[i].b[(m+1)%3],a[i].b[(m+2)%3]);
			//cout<<a[i].b[(m+1)%3]<<endl;
			a[i].b[(m+2)%3]=a[i].b[m]-a[i].b[(m+1)%3];
		}
		
		sort(a+1,a+n+1,cmp);
		
		//for(int i=1;i<=n;i++) cout<<a[i].b[1]<<" ";
		//cout<<endl;
		ans=0;
		
		for(int i=1;i<=n;i++){
			if(i<=n/2) ans+=a[i].b[(m+1)%3];	
			else ans+=a[i].b[m];	
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
 
1
2
10 9 8
4 0 0
*/
 

