#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long T,a1[N],a2[N],a3[N],ans,sum;
int book[4];
bool cmp(int a,int b){
	return a>b;
}
void DFS(int n,int zong){
	if(n>zong){
		ans=max(ans,sum);
		sum=0;
		return;
	}
	for(int i=1;i<=3;i++){
		if(book[i]<=n/2){
			book[i]++;
			if(i==1){
				sum+=a1[n];
				DFS(n+1,zong);
			}
			if(i==2){
				sum+=a2[n];
				DFS(n+1,zong);
			}
			if(i==3){
				sum+=a3[n];
				DFS(n+1,zong);
			}
			//for(int j=1;j<=n;j++) cout<<book[i]<<' ';
			//cout<<endl;
			//cout<<sum<<' '<<n<<endl;
			book[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		//DFS(1,n);
		//cout<<a2[1]<<' ';
		if(a2[1]==0){
			sort(a1+1,a1+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a1[i];
			}
			cout<<ans<<endl;
			ans=0;
		}else if(a3[1]==0){
			sort(a1+1,a1+n+1,cmp);
			sort(a2+1,a2+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a1[i];
			}
			for(int i=1;i<=n/2;i++){
				ans+=a2[i];
			}
			cout<<ans<<endl;
			ans=0;
		}else{
			//DFS(1,n);
			for(int i=1;i<=n;i++){
				ans+=max(a1[i],max(a2[i],a3[i]));
			}
			cout<<ans<<endl;
			ans=0;
		}
	}	
	return 0;
}
