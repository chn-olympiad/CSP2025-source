#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[100005][5];
struct node{
	int val,d;
};
node A[100005];
int tot=0;
int t[5];//每个里面最大值 
// long long !
bool cmp(node a,node b){
	return a.d<b.d;
}
int work(){
	cin>>n;
	int sum=0;
	memset(t,0,sizeof(t));
	memset(A,0,sizeof(A));
	tot=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++){
		int r=max(max(a[i][1],a[i][2]),a[i][3]);
		sum+=r;
		if(r==a[i][1]){
			t[1]++;
			continue;
		}
		if(r==a[i][2]){
			t[2]++;
			continue;
		}
		if(r==a[i][3]){
			t[3]++;
			continue;
		}
	}
	if(t[1]<=n/2&&t[2]<=n/2&&t[3]<=n/2){
		return sum;
	}
	int p=1,ove;
	for(int i=1;i<=3;i++){
		if(t[i]>n/2){
			p=i;
			ove=t[i]-n/2;
			break;
		}
	}
	//找到超过的列 
	for(int i=1;i<=n;i++){
		int r=max(max(a[i][1],a[i][2]),a[i][3]);
		if(r==a[i][p]){
			A[++tot].val=a[i][p];
			if(p==1) A[tot].d=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			if(p==2) A[tot].d=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			if(p==3) A[tot].d=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);	
		}
	}
	sort(A+1,A+1+tot,cmp);
	int dsum=0;
	for(int i=1;i<=ove;i++){
		dsum+=A[i].d;
	}
	return sum-dsum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cout<<work()<<"\n";
	}
	return 0;
}


