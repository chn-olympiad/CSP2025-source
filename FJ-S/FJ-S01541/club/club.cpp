#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ioimprove(); ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FILE(x); freopen(x".in","r",stdin);freopen(x".out","w",stdout);
struct node
{
	int _,__,_o_,d;
}a[114514];
int t,n;
bool cmp(node x,node y)
{
	return max(max(x._,x.__),x._o_) >= max(max(y._,y.__),y._o_);
}
bool cmp2(node x,node y)
{
	if(max(max(x._,x.__),x._o_) != x._) return 0;
	if(max(max(y._,y.__),y._o_) != y._) return 1;
	return x.d < y.d;
}
bool cmp3(node x,node y)
{
	if(max(max(x._,x.__),x._o_) != x.__) return 0;
	if(max(max(y._,y.__),y._o_) != y.__) return 1;
	return x.d < y.d;
}
bool cmp4(node x,node y)
{
	if(max(max(x._,x.__),x._o_) != x._o_) return 0;
	if(max(max(y._,y.__),y._o_) != y._o_) return 1;
	return x.d < y.d;
}
bool cmp5(node x,node y)
{
	if(max(max(x._,x.__),x._o_) != x._) return 0;
	if(max(max(y._,y.__),y._o_) != y._) return 1;
	return x.d > y.d;
}
bool cmp6(node x,node y)
{
	if(max(max(x._,x.__),x._o_) != x.__) return 0;
	if(max(max(y._,y.__),y._o_) != y.__) return 1;
	return x.d > y.d;
}
bool cmp7(node x,node y)
{
	if(max(max(x._,x.__),x._o_) != x._o_) return 0;
	if(max(max(y._,y.__),y._o_) != y._o_) return 1;
	return x.d > y.d;
}
signed main()
{
	FILE("club");
	ioimprove();
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 1;i <= n;i++) 
		{
			cin>>a[i]._>>a[i].__>>a[i]._o_;
			if(a[i]._ == max(max(a[i]._,a[i].__),a[i]._o_)) a[i].d = a[i]._ - max(a[i].__,a[i]._o_);
			else if(a[i].__ == max(max(a[i]._,a[i].__),a[i]._o_)) a[i].d = a[i].__ - max(a[i]._,a[i]._o_);
			else if(a[i]._o_ == max(max(a[i]._,a[i].__),a[i]._o_)) a[i].d = a[i]._o_ - max(a[i].__,a[i]._);
		}
		sort(a + 1,a + n + 1,cmp);
		int cnt1 = 0,cnt2 = 0,cnt3 = 0,sum = 0,tiaocao = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i]._ == max(max(a[i]._,a[i].__),a[i]._o_))
			{
				if(cnt1 < n / 2ll) 
				{
					cnt1++,sum += a[i]._;
					if(cnt1 == n / 2ll && i != n) {sort(a + 1,a + i + 1,cmp2);sort(a + i + 2,a + n + 1,cmp5);}
				}
				else 
				{
					if(a[i].d > a[tiaocao + 1].d) sum += (a[i].d - a[++tiaocao].d);
					sum += max(a[i].__,a[i]._o_);
				}
			}
			else if(a[i].__ == max(max(a[i]._,a[i].__),a[i]._o_))
			{
				if(cnt2 < n / 2ll) 
				{
					cnt2++,sum += a[i].__;
					if(cnt2 == n / 2ll && i != n) {sort(a + 1,a + i + 1,cmp3);sort(a + i + 2,a + n + 1,cmp6);}
				}
				else 
				{
					if(a[i].d > a[tiaocao + 1].d) sum += (a[i].d - a[++tiaocao].d);
					sum += max(a[i]._,a[i]._o_);
				}
			}
			else if(a[i]._o_ == max(max(a[i]._,a[i].__),a[i]._o_))
			{
				if(cnt3 < n / 2ll) 
				{
					cnt3++,sum += a[i]._o_;
					if(cnt3 == n / 2ll && i != n) {sort(a + 1,a + i + 1,cmp4);sort(a + i + 2,a + n + 1,cmp7);}
				}
				else 
				{
					if(a[i].d > a[tiaocao + 1].d) sum += (a[i].d - a[++tiaocao].d);
					sum += max(a[i].__,a[i]._);
				}
			}
		}
		cout<<sum<<"\n";
	}
	
	
	return 0;
}
/*
1
30
18198 13027 19770_
7616 1139 19916_
14531 8412 19487_
15314 3789 19173_
12545 5185 19009_
18932_ 9546 2865
3331 351 18764_
12742 18687_ 2815
10233 490 18645_
6223 3907 18331_
14061 2936 18146_
8216 497 17311_
6854 1555 17206_
17146_ 10238 6221
9412 2951 16747_
9859 2477 16696_
6734 16641_ 13734
11792 4634 16269_

11326 7358 16023_
12210 4057 15760_
8832 8638 15352_
7348 703 14149_
11562 2215 13762_
11343 4548 12436_
11524 8584 12424_
11595 10431 12257_
10457 5645 11050_
4359 3830 8631_
1596 1197 4624_
2094 1772 3950_
*/


/*
1
30
7348 703 14149
11524 8584 12424
17146 10238 6221
11343 4548 12436
6734 16641 13734
9412 2951 16747
10457 5645 11050
8832 8638 15352
4359 3830 8631
6854 1555 17206
12210 4057 15760
2094 1772 3950
11792 4634 16269
12742 18687 2815
7616 1139 19916
11595 10431 12257
9859 2477 16696
15314 3789 19173
3331 351 18764
18198 13027 19770
11562 2215 13762
10233 490 18645
8216 497 17311
12545 5185 19009
14061 2936 18146
6223 3907 18331
18932 9546 2865
11326 7358 16023
1596 1197 4624
14531 8412 19487

*/
