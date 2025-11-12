#include<bits/stdc++.h>
using namespace std;
int t,tpa;
int n,maxx;
int a[100005][5];
int tpaa[100005];
int r[5];
int dfs(int d,int sum){
	if(d==n+1){
		return sum;
	}
	int ans=0;
	for(int i=1;i<=3;i++){
		if(r[i]<n/2){
			r[i]++;
			ans=max(ans,dfs(d+1,sum+a[d][i]));
			r[i]--;
		}
	}
	return ans;
}
bool cmp(int dyl1,int dyl2){
	return dyl1>dyl2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	tpa=0;
    	tpb=0;
    	maxx=0;
    	memset(r,0,sizeof(r));
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		cin>>a[i][1]>>a[i][2]>>a[i][3];
    		tpaa[i]=a[i][1];
			if(a[i][2]!=0||a[i][3]!=0){
				tpa=1;
			}
		}
		if(!tpa){
			sort(tpaa+1,tpaa+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=tpaa[i];
			}
			cout<<sum<<endl;
		}else{
			cout<<dfs(1,0)<<endl;
		}
    }
	return 0;
}
