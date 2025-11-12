#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm> 
using namespace std;
int pre[5*114514];
int a[5*114514];
int b[5*114514];
int n,k,i,j,m,st,ans=1,minr,wh;
struct zu{
	int l;
	int r;
};
vector<zu>qu;
bool cmp(zu z1, zu z2)
{
	if (z1.r == z2.r)return z1.l<z2.l;
	else return z1.r<z2.r;
}
int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(pre,0,sizeof(pre));
	n=m=i=j=k=wh,0;
	ans =1;
	qu.clear();
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (i=1; i<=n; i++) cin >> a[i], pre[i]=(pre[i-1]^a[i]);
	for (i=1; i<=n; i++)
	{
		for (j=1;j<=i;j++)
			{
			//cout << int(pre[i] ^ pre[j-1]) << endl; 
			if ((pre[i] ^ pre[j-1]) == k)
				{
//				printf("%d xor %d == %d\n", pre[i],pre[j-1],k);
				qu.push_back({j,i});
				}
			}
	}
//	for (i=0; i< qu.size(); i++)
//		 cout << qu[i].l << " " << qu[i].r<<" ";
//	cout << endl;
	if (qu.size() == 0){
		cout << 0;
		return 0;
	}
	sort (qu.begin(), qu.end(), cmp);
	st = qu[0].r;
	qu.erase(qu.begin());
	minr=2147483647;
	while (!qu.empty())
	{
		minr=2147483647;
		for (i=0;i<qu.size();i++)
			if (qu[i].l>st and qu[i].r < minr) minr = qu[i].r, wh = i;
		if (minr == 2147483647)break;
		ans ++ ;
		st = minr;
		qu.erase(qu.begin()+wh);
	}
	cout << ans; 
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
