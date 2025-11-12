#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],sum[N],path[N][3],ans=-1;
long long k,f[1010][1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	sum[1]=a[1];
	sum[0]=0;
	int num=0;
	f[1][1]=sum[0]^sum[1];
	if(f[1][1]==k){
		path[1][1]=1,path[1][2]=1;
		num++;
	}
	for(int i=2;i<=n;i++){
		cin>>a[i];
		sum[i]=int(sum[i-1]^a[i]);
		for(int j=1;j<=i;j++){
			f[i][j]=int(sum[j-1]^sum[i]);
			if(f[i][j]==k){
				num++;
				path[num][1]=j;
				path[num][2]=i;
			}
		}
	}
	for(int i=1;i<=num;i++){
		int ansn=1;
		int head,tail=path[i][2];
		for(int j=i+1;j<=num;j++){
			head=path[j][1];
			if(head>tail){
				ansn++;
				tail=path[j][2];
			}
		}
		ans=max(ans,ansn);
	}
	cout<<ans<<endl;
	return 0;
} 
