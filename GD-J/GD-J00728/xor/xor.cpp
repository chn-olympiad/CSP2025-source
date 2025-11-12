#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10010];
int ans;
void dfs(int l,int r)
{
	if(l==n) return;
	int x=0;
	for(int i=l;i<=r;i++)
		x= x xor a[i];
	if(x==k)
	{
		ans++;
	}

	if(r+1<=n) dfs(l,r+1);
	if(r+1>n) dfs(l+1,1);

}


int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];	
	dfs(1,1);
	
	cout<<ans;

    return 0;
}





//我是真的看不懂题目啊 啊啊啊啊啊，ccf求你放过我吧啊啊啊啊啊，怎么不向去年一样可以打暴力导出来了啊啊啊
//你变了ccf，你以前不是这样的，还记得2019年的秋天吗
//那次不管怎么拒绝你，你都会给我们45分啊，总司令，nibianle 










//不是，xor是啥啊？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？ 
//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout); 

//#include<bits\stdc++.h>
 

