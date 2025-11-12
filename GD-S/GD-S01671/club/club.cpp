#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
bool flag;
int t,n;
int a[N][5];
int f[250][250][250];
struct stu{
	int a1,a2,k;
}node[N];
bool cmp(stu a,stu b){
	return a.k>b.k;
}
int work1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i-j;k++){
				if(j>=1)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
				if(k>=1)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
				if(j+k<=i-1)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]); 
			}
		}
	}
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=n/2;j++){
			if(n-i-j<=n/2)ans=max(ans,f[n][i][j]);
		}
	}
	return ans;
}
int work2(){
	for(int i=1;i<=n;i++){
		node[i].a1=a[i][1];
		node[i].a2=a[i][2];
		node[i].k=abs(node[i].a1-node[i].a2);
	}
	sort(node+1,node+n+1,cmp);
	int sum1=0,sum2=0,ans=0;
	for(int i=1;i<=n;i++){
		if(sum1==n/2)ans+=node[i].a2;
		else if(sum2==n/2)ans+=node[i].a1;
		else if(node[i].a1>=node[i].a2){
			ans+=node[i].a1;
			sum1++;
		}
		else{
			ans+=node[i].a2;
			sum2++;
		}
	}
	return ans;
}
int work3(){
	int sum=0;
	for(int i=1;i<=n;i++)sum+=max(max(a[i][1],a[i][2]),a[i][3]);
	return sum;
}
signed main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//14:30-15:22 DP O(N^3) expect:55pts
	//15:23-15:50 性质B O(nlogn) expect:15pts
	//16:05 经历重重困难终于拍上了！ 
	//16:09 性质C应该是给贪心吧...expect:[0,10]pts 
	cin>>t;
	while(t--){
		flag=1;
		memset(f,0,sizeof f);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3]!=0)flag=0;
		}
		if(flag==1)cout<<work2()<<endl;
		else if(n<=200)cout<<work1()<<endl;
		else cout<<work3()<<endl;
	}
	return 0;
}
