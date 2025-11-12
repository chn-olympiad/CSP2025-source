#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][4],num[4],ans,pc[N],ch[N],q[N],len;
int ip;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		ip=0,len=0,ans=0;
		memset(num,0,sizeof(num));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				num[1]++,ans=ans+a[i][1],ch[i]=1;
				if(a[i][2]>a[i][3]) pc[i]=a[i][2]-a[i][1];
				else pc[i]=a[i][3]-a[i][1];
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				num[2]++,ans=ans+a[i][2],ch[i]=2;
				if(a[i][1]>a[i][3]) pc[i]=a[i][1]-a[i][2];
				else pc[i]=a[i][3]-a[i][2];
			}else{
				num[3]++,ans=ans+a[i][3],ch[i]=3;
				if(a[i][1]>a[i][2]) pc[i]=a[i][1]-a[i][3];
				else pc[i]=a[i][2]-a[i][3];
			}
		}
		if(num[1]>n/2) ip=1;
		else if(num[2]>n/2) ip=2;
		else if(num[3]>n/2) ip=3;
		if(!ip){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(ch[i]==ip) q[++len]=pc[i];
		}
		sort(q+1,q+len+1,cmp);
		for(int i=1;i<=len-n/2;i++) ans=ans+q[i];
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
