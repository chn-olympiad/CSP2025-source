#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10,M=4e6+10;
long long n,k;
long long a[N],b[N],sum,ans;
bool bj[N];
struct ff{
	long long x,y,c;
}z[M];
bool cmp(ff q,ff w){
	if(q.c!=w.c)return q.c<w.c;
	else if(q.x!=w.x)return q.x<w.x;
	else return q.y<w.y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
		if(a[i]==k)sum++,z[sum].x=i,z[sum].y=i,z[sum].c=1;
		if(b[i]==k)sum++,z[sum].x=1,z[sum].y=i,z[sum].c=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++){
			long long su=(long long)(b[j]^b[i-1]);
			if(su==k)sum++,z[sum].x=i,z[sum].y=j,z[sum].c=j-i+1;	
		}
	}
	sort(z+1,z+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		int pd=0;
		for(int j=z[i].x;j<=z[i].y;j++){
			if(bj[j]==1){
				pd=1;
				break;
			}
		}
		if(pd==0)ans++;
		for(int j=z[i].x;j<=z[i].y;j++)bj[j]=1;
	}
	cout<<ans;
	return 0;
}
