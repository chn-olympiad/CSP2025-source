#include <bits/stdc++.h>
using namespace std;
const int siz=5e5+10,ran=(1<<20)+5;
int swc[ran],a[siz];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(swc,-0x3f,sizeof swc);
	int n,k,la=0,ans=0;
	cin>>n>>k;
	swc[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],a[i]^=a[i-1];
		int shu=swc[k^a[i]];
	//	cerr<<shu<<'\n';
		if(shu>=la)la=i,ans++;
		swc[a[i]]=i;
	}
	cout<<ans<<'\n';
	return 0;
}
//what a rick!
//9:05 finish debug.
/*
X...X..OOO..RRRR.
.X.X..O...O.R...R
..X...O...O.RRRR.
.X.X..O...O.R..R.
X...X..OOO..R...R

freepen("xor".",in","r",stdout);
*/