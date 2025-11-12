#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],op[100005],b[5],ans,xiang[100005],guai[100005],sha[100005];
void dfs(int k){
	if(k>n){
		int sss=0;
		for(int i=1;i<=n;i++){
			sss+=a[i][op[i]];
			//cout<<op[i]<<" ";
		}
		ans=max(ans,sss);
	}
	for(int i=1;i<=3;i++){
		op[k]=i;
		b[i]++;
		
		if(b[i]<=n/2)dfs(k+1);
		
		b[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){cin>>a[i][1]>>a[i][2]>>a[i][3];xiang[i]=a[i][1],guai[i]=a[i][2],sha[i]=a[i][3];}
		ans=0;
		if(n<=10){		 
			ans=-1;
			dfs(1);
		}else{
			sort(xiang+1,xiang+n+1);
			sort(guai+1,guai+n+1);
			sort(sha +1,sha +n+1);
			if(guai[n]==0&&sha[n]==0){
				for(int i=n/2+1;i<=n;i++)ans+=xiang[i];
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
} 
