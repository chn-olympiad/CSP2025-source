#include<bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a);i<=(int)(b);i++)
using namespace std;
int n;
int t;
int ans;
int d[4];
int clup[4];
int clup_a[50001];
int clup_b[50001];
int clup_p[4];
struct Node{
	int first;//满意度最高的 
	int firstp;//第几个社团 
	int second;//满意度第二高
	int secondp;//第几个社团 
	int sub;//最高与第二高的差值 
}a[100001];
bool cmp(Node x,Node y){
	return x.first>y.first;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(clup,0,sizeof(clup));
		memset(clup_a,0,sizeof(clup_a));
		memset(clup_b,0,sizeof(clup_b));
		memset(clup_p,0,sizeof(clup_p));
//		memset(a,0,sizeof(a));
		int a1=0;
		int b1=0;
		ans=0;
		bool flag=false;//判断是否有某个社团的人数超过一半 
		cin>>n;
		FOR(j,1,n){
			int maxn=0;
			int maxp=0;
			FOR(i,1,3){
				cin>>d[i];
				if(d[i]>maxn) maxn=d[i],maxp=i;
			}
			a[j].first=d[maxp];
			a[j].firstp=maxp;
			maxn=0;
			int maxp2=0;
			FOR(i,1,3){
				if(d[i]>maxn&&i!=maxp) maxn=d[i],maxp2=i;
			}
			a[j].second=d[maxn];
			a[j].secondp=maxp2;
//			cout<<a[j].sub;
			a[j].sub=d[maxp]-d[maxp2];//非负数 
//			cout<<a[j].sub<<endl;
		}
		sort(a+1,a+1+n,cmp);
//		FOR(i,1,n) cout<<a[i].first;
		FOR(i,1,n){
			if(clup_p[1]<(n/2)&&clup_p[2]<(n/2)&&clup_p[3]<(n/2)) {
				ans+=a[i].first;
				clup_p[a[i].firstp]++;
				clup_a[++a1]=a[i].sub;
//				cout<<ans<<" ";
			}
			else {
				flag=true;
//				cout<<"@@@";
				ans+=a[i].second;
//				cout<<ans<<" ";
				clup_b[++b1]=a[i].sub;
			}	 
		}
		if(flag){//存在有人无法去自己最满意的社团 
			sort(clup_a+1,clup_a+1+n/2);
			sort(clup_b+1,clup_b+1+n/2);
			FOR(i,1,n/2){
//				cout<<"^_^";
//				cout<<clup_a[i]<<" "<<clup_b[i]<<" ";
				if(clup_a[i]<clup_b[i]) ans+=(clup_b[i]-clup_a[i]);
				else break;
			} 
		}
//		cout<<clup_p[1]<<" "<<clup_p[2]<<" "<<clup_p[3]<<endl;
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1.一个人的三个社团中，满意度最小的社团一定不会去
  只会在满意度第一和第二的社团中选择一个 

ask： 
2
10 9 8 
4  0 0 
1.为什么第一个人不选第一个社团，而是选择第二个社团
  因为第二个人第一个社团加第一个人的第二个社团的选择值更高 
2.怎么样判断某一个人应该去满意度第二的社团而不是最满意的社团
  那个人去满意度第二的社团减去满意度第一的社团
  小于另外一个人去第二满意度的社团减去满意度第一的社团
 
思路：
将每一个人都设有两个预选社团，为AB，A满意度最高，B第二
再算每一个人A-B的差值
首先每个人一定要先去满意度最高的社团 

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0 
0 2 0 
0 1 0
0 2 0
2
10 9 8 
4 0 0 



bushi,freopen输出为空？ 
bushi,CCF给的样例格式有问题啊？？？ 
*/

