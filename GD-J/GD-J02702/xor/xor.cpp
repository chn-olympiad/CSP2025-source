#include<bits/stdc++.h>//#Shang4Shan3Ruo6Shui4
#define ll long long
#define endl "\n"
using namespace std;
int n,k,ans;
int a[500005],sum[500005];
int le[500005],ri[500005];
vector<int>fir[3000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	fir[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1)sum[i]=sum[i-1] xor a[i];
		else sum[i]=a[i];
		fir[sum[i]].push_back(i);
	}
	for(int r=1;r<=n;r++)//枚举右节点 
	{
		int suml=sum[r] xor k;//suml是要找值为suml的sum
		if(fir[suml].empty())continue;//不存在这样的左节点
		int len=fir[suml].size(),l=0;
		for(l=0;l<len && fir[suml][l]<r;l++);
		l--;
		if(fir[suml][l]>r)continue;//r前面没有这个点
		l=fir[suml][l]+1;//把l转成左端点的下标 
		if(l>r)continue; 
		int posl=lower_bound(le+1,le+ans+1,l)-le;
		int posr=lower_bound(ri+1,ri+ans+1,l)-ri;
		if((l<=le[posl] && le[posl]<=r) || (l<=ri[posr] && ri[posr]<=r))continue;//有相交 
		ans++;
		le[ans]=l;ri[ans]=r;
//		cout<<l<<' '<<r<<endl;
	}
	cout<<ans;
	return 0;
}
