#include<bits/stdc++.h>
using namespace std;
//a
long long a[500001],ma,dp[500001];
//a长 i j
int n,k;
int i,j,ki,r;
//当l=i时的r
int ar[500001];
bool b;

//十转倒二 
string uttt(long long x)
{
	string ua;
	long long i=1;
	//cout<<x<<endl;
	while(x!=0){
		ua[i]=x%2;cout<<x%2;
		x=x/2;
		i++;
		}cout<<endl;
	return ua;
}

//亦或结果
long long yihuo(int x,int y)
{
	long long i,ans=0,n,m=1;
	if(x<=1&&y<=1){
		if(x==y)return 0;
		else return 1;
		}
	string as,sx=uttt(x),sy=uttt(y);
	
	n=max(sx.size(),sy.size());
	for(i=0;i<=n-1;i++,m=m*2){
		as[i]=!((sx[i]==1)&&(sy[i]==1));
		ans+=as[i]*m;
		}
	return ans;
}

int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	//求ar
	//for(i=1;i<=n;i++){
	//	b=0;j=0;
	//	while(ar[i]<=n){
	//		ki=yihuo(ki,a[j]);
	//		j++;
	//		if(ki==k){
	//			ar[i]=i+j;
	//			b=1;
	//			break;
	//			}
	//		}
	//	if(!b)ar[i]=-1;
	//	}
	
	for(i=n;i>=1;i--){
		if(ar[i]==-1)continue;
		ma=-1;
		for(j=i;j<=ar[i];j++)
			ma=max(ma,dp[i+j]);
		dp[i]=ma+1;
		}
	
	for(i=1;i<=n;i++)
		ma=max(ma,dp[i]);
	cout<<ma;
	
	//-----------------------
	
	//for(i=1;i<=n;i++){
	//	for(j=0;j<=a2[i].size()-1;j++)
	//		cout<<a2[i][j]+'0'<<' ';
	//	cout<<endl;
	//	}
	
	//-----------------------
	cout<<yihuo(1,2);
	return 0;
	
	cout<<1;
}
