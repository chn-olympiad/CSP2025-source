#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int x[maxn][5];
struct node{
	int a,sum;
};
node a[maxn],b[maxn],c[maxn];
bool cmp1(node x,node y){
	return x.sum>y.sum;
}
bool cmp2(node x,node y){
	return x.sum>y.sum;
}
bool cmp3(node x,node y){
	return x.sum>y.sum;
}
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		memset (a,0,sizeof a);
		memset (b,0,sizeof b);
		memset (c,0,sizeof c);
		int flag1=0;
		int c1=0,c2=0,c3=0;
		for (int i=1;i<=n;i++){
			cin>>x[i][1]>>x[i][2]>>x[i][3];
			if (x[i][2]!=0||x[i][3]!=0){
				flag1=1;
			}
			if (x[i][1]>x[i][2]&&x[i][1]>x[i][3]){
				c1++;
				a[c1]={i,x[i][1]};
			}
			else if (x[i][1]<x[i][2]&&x[i][2]>x[i][3]){
				c2++;
				b[c2]={i,x[i][2]};
			}
			else {
				c3++;
				c[c3]={i,x[i][3]};
			}
		}
		if (flag1==0){
			//cout<<"a";
			sort (a+1,a+1+c1,cmp1);
			long long ans=0;
			for (int i=1;i<=n/2;i++){
				ans+=a[i].sum;
			}
			cout<<ans<<"\n";
		}
		else {
			sort (a+1,a+1+c1,cmp1);
			sort (b+1,b+1+c2,cmp2);
			sort (c+1,c+1+c3,cmp3);
			int k1=min(n/2,c1),k2=min(n/2,c2),k3=min(n/2,k3);
			long long  res=0;
			for (int i=1;i<=k1;i++){
				//cout<<a[i].sum<<" "<<1<<"\n";
				res+=a[i].sum;
			}
			for (int i=1;i<=k2;i++){
				res+=b[i].sum;
				//cout<<a[i].sum<<" "<<2<<"\n";
			}
			for (int i=1;i<=k3;i++){
				res+=c[i].sum;
				//cout<<a[i].sum<<" "<<3<<"\n";
			}
			//cout<<res<<"\n";
			if ((c1>n/2&&c2>n/2&&c3>n/2)||(c1<=n/2&&c2<=n/2&&c3<=n/3)){ 
				cout<<res<<"\n";
			}
			else {
			if (c1>n/2){
			//cout<<"a";
			int q1=c1-n/2;
			cout<<q1;
			if (c2<n/2){
				int s1=min(n/2-c2,q1);
				for (int i=n/2+1;i<=n/2+s1;i++){
					res+=a[i].sum;
					//cout<<a[i].sum<<" ";
				}
				q1-=s1;
			}
			if (c3<n/2){
				int s2=min(n/2-c3,q1);
				for (int i=n/2+1;i<=n/2+s2;i++){
					res+=a[i].sum;
					//cout<<a[i].sum<<" ";
				}
			}
			//cout<<res<<"\n";
		}
		if (c2>n/2){
			cout<<"b";
			int q2=c2-n/2;
			if (c1<n/2){
				int s1=min(n/2-c1,q2);
				for (int i=n/2+1;i<=n/2+s1;i++){
					res+=b[i].sum;
				}
				q2-=s1;
			}
			if (c3<n/2){
				int s2=min(n/2-c3,q2);
				for (int i=n/2+1;i<=n/2+s2;i++){
					res+=b[i].sum;
				}
			}
		}
		if (c3>n/2){
			//cout<<"c";
			int q3=c3-n/2;
			if (c1<n/2){
				int s1=min(n/2-c1,q3);
				for (int i=n/2+1;i<=n/2+s1;i++){
					res+=c[i].sum;
				}
				q3-=s1;
			}
			if (c2<n/2){
				int s2=min(n/2-c2,q3);
				for (int i=n/2+1;i<=n/2+s2;i++){
					res+=c[i].sum;
					}
				}
			}
		cout<<res<<"\n";
		}
		}
	}
	return 0;
}
