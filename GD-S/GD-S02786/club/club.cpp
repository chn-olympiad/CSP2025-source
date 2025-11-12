#include<bits/stdc++.h>
using namespace std;
long long ans;
bool cmp(int x,int y){
	return x>y;
}
const int Mx=2e5+100;
int n,a[Mx][5],wt[Mx],as[Mx],b[Mx];
void sv(){
	ans=0;
	cin>>n;
	memset(a,0,sizeof(a));
	memset(wt,0,sizeof(wt));
	memset(as,0,sizeof(as));memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=max(a[i][2],a[i][3]))wt[i]=1;
		if(a[i][2]>=max(a[i][1],a[i][3]))wt[i]=2;
		if(a[i][3]>=max(a[i][2],a[i][1]))wt[i]=3;
		ans+=a[i][wt[i]];
		as[wt[i]]++;
	}
	int wr=0;
	if(as[1]>n/2)wr=1;
	if(as[2]>n/2)wr=2;
	if(as[3]>n/2)wr=3;
	if(wr==0){
		cout<<ans<<"\n";
		return;
	}
	int len=0;
	for(int i=1;i<=n;i++){
		if(wt[i]==wr){
			b[++len]=-a[i][wr];
			int tp1=0;
			if(wr==1)tp1=max(a[i][2],a[i][3]);
			if(wr==2)tp1=max(a[i][1],a[i][3]);
			if(wr==3)tp1=max(a[i][2],a[i][1]);
			b[len]+=tp1;
		}
	}
	sort(b+1,b+len+1,cmp);
	for(int i=1;i<=as[wr]-n/2;i++){
		ans+=b[i];
	}
	cout<<ans<<"\n";
}
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)sv();
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
