#include<bits/stdc++.h>
using namespace std;
int a[5010],sum[5010];
int t1=0,t2=0,t3=0;//t1为总和加起来要小于多少；t2为一共选到第几个；t3为到现在的和 
int xz(int k,int t)//k为现在是第几个
{
	if(t2<k)return 0;
	int ret=0;
	t3+=a[k];
	if(t3<t1)ret+=xz(k+1,1);
	t3-=a[k];
	ret+=xz(k+1,0);
	if(t!=0)ret++;
	return ret;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ret=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		sum[i]=a[i]+sum[max(i-1,0)];
	}
	for(int i=n-1;i>=0;i--)
	{
		int cnt=sum[i-1]-a[i];
		t1=cnt,t2=i-1,t3=0;
		if(cnt>=0)ret+=xz(0,1);
//		cout<<cnt<<' '<<ret<<endl;
	}
	cout<<ret;
//	cout<<1;
	return 0;
}
