#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
const int N=2e6+10,inf=0x3f3f3f3f,mod=1e9+7;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;
/*
09:42
Task3 done.

09:43
Hack by xor5.in

09:45
I want to try solve this task with vector.

09:47 
How to use vector???
I want to play ADOFAI.

09:57
No lower_bound?
Using set again.
CE

Wait.

10:00
I KNOW HOW TO USE SET NOW!!!
WA on xor1

10:13
WA on xor5 again
Some problem in my code...
My Solution was Wrong!!!

10:21
Recode.
WA on xor2

10:23
IT PASS XOR5/6 !!!!!!!
I want to play ADOFAI.
*/
pii ts[N];
set<int> FinalHope[N];
int n,k,a[N],p[N],cnt,ans;
int find(int x,int f){
	set<int>::iterator r=FinalHope[f].lower_bound(x);
	return r==FinalHope[f].end()?0:*r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) p[i]=p[i-1]^a[i],FinalHope[p[i]].insert(i);
	for(int i=1,r;i<=n;i++)
		if((r=find(i,p[i-1]^k))!=0) ts[++cnt]={r,i};
	sort(ts+1,ts+cnt+1);
	int r=0;
	for(int i=1;i<=cnt;i++) 
		if(ts[i].y>r) r=ts[i].x,++ans;
	cout<<ans;
	return 0;
}

