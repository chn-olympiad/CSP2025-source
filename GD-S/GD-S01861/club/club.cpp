#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long a[100005][4];
long long num1,num2,num3;
long long ans;
long long b[100005];
int cnt;
int tepan1,tepan2; 
void dfs(int x,long long q){
	if(x==n+1){
		ans=max(ans,q);
		return ;
	}
	num1++;
	if(num1<=n/2 && num2<=n/2 && num3<=n/2){
		dfs(x+1,q+a[x][1]);
	}
	num1--;
	num2++;
	if(num1<=n/2 && num2<=n/2 && num3<=n/2){
		dfs(x+1,q+a[x][2]);
	}
	num2--;
	num3++;
	if(num1<=n/2 && num2<=n/2 && num3<=n/2){
		dfs(x+1,q+a[x][3]);
	}
	num3--;
	return ; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2 && a[i][j]!=0){
					tepan1=1;
				}
				if(j==3 && a[i][j]!=0){
					tepan2=1;
				}
			}
			b[i]=a[i][1];
		}
		if(tepan1==0 && tepan2==0){
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i++){
				ans+=b[i];
			}
			cout<<ans;
		}else{
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
