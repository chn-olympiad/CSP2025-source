#include <bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
int a[100001][7],dis[3];
struct l{
	int id,o1,o2,o3,a1,a2,a3;
}b[100001];
void f(int x,int sum){
	if(x>n){
		if(sum>ans) ans=sum;
		return;
	}
	for(int i=1;i<=3;i++){
		if(dis[i]<n/2){
			dis[i]++;
			f(x+1,sum+a[x][i]);
			dis[i]--;
		}
	}
}
bool cmp(l x,l y){
	if(x.o1>y.o1){
		return true;
	}else if(x.o1<y.o1){
		return false;
	}else{
		if(x.o2<y.o2){
			return true;
		}else if(x.o2>y.o2){
			return false;
		}else{
			if(x.o3<y.o3){
				return true;
			}else{
				return false;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		int ak[n+1],k=1,k2=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}ak[i]=a[i][1];
			if(a[i][2]!=0 || a[i][3]!=0) k=0;
			if(a[i][3]!=0) k2=0;
			if(a[i][1]>=a[i][2]){
				if(a[i][1]>=a[i][3]){
					a[i][4]=1;
					if(a[i][2]>=a[i][3]) a[i][5]=2,a[i][6]=3;
					else a[i][5]=3,a[i][6]=2;
				}else{
					a[i][4]=3,a[i][5]=1,a[i][6]=2;
				}
			}else{
				if(a[i][1]>=a[i][3]){
					a[i][4]=2,a[i][5]=1,a[i][6]=3;
				}else{
					a[i][6]=1;
					if(a[i][2]>=a[i][3]) a[i][4]=2,a[i][5]=3;
					else a[i][4]=3,a[i][5]=2;
				}
			}
			b[i].id=i;
			b[i].o1=a[i][a[i][4]];
			b[i].o2=a[i][a[i][5]];
			b[i].o3=a[i][a[i][6]];
			b[i].a1=a[i][4];
			b[i].a2=a[i][5];
			b[i].a3=a[i][6];
		}
		sort(ak+1,ak+n+1);
		if(k){
			for(int j=n;j>n/2;j--){
				ans+=ak[j];
				
			}cout<<ans<<endl;
		}else if(n<=20){
			f(1,0);
			cout<<ans<<endl;
		}else if(k2){
			
		}else{
			sort(b+1,b+n+1,cmp);
			int t[4]={0,0,0,0};
			for(int i=1;i<=n;i++){
				if(t[b[i].a1]<n/2){
					t[b[i].a1]++;
					ans+=b[i].o1;
				}else if(t[b[i].a2]<n/2){
					t[b[i].a2]++;
					ans+=b[i].o2;
				}else{
					t[b[i].a3]++;
					ans+=b[i].o3;
				}
			}
			cout<<ans<<endl;
		} 

		
	}
	return 0;
}
