#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t;
long long a[maxn][4];
long long x1[maxn],x2[maxn],x3[maxn];
bool cmp(long long x,long long y){
	return x>y;
}
int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long ans=0,f1=0,f2=0,f3=0;
		long long n;
		cin>>n;
		long long res=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			x1[i]=a[i][1];
			x2[i]=a[i][2];
			x3[i]=a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) f1=1;
			if(a[i][1]!=0||a[i][2]!=0) f2=1;
			if(a[i][1]!=0||a[i][3]!=0) f3=1;
		}
		if(f1==0){
			sort(x1+1,x1+n+1,cmp);
			for(int i=1;i<=res;i++){
				ans+=x1[i];
			}
		}else if(n==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=n;k++){
						for(int o=1;o<=3;o++){
							if(j!=o&&i!=k) ans=max(ans,a[i][j]+a[k][o]); 
						}
					}
				}
			}
		}else if(f2==0){
			sort(x3+1,x3+n+1,cmp);
			for(int i=1;i<=res;i++){
				ans+=x3[i];
			}
		}else if(f3==0){
			sort(x2+1,x2+n+1,cmp);
			for(int i=1;i<=res;i++){
				ans+=x2[i];
			}
		}else{
			for(int i=1;i<=n;i++){
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
