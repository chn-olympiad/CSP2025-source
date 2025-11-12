#include<bits/stdc++.h>
using namespace std;
#define ak ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//don't use fclose
//不开ll___
//数组开小直接炸
#define sqrt sqrtl
#define int long long
const int maxn=500005;
int a[maxn],qx[maxn],le[maxn],ans=0;
inline int randr(int l,int r){return rand()%(r-l+1)+l;}
#define randf(l,r) for(int i=l;i<=r;i=randr(l,r))
//
inline int get(int l,int r){return qx[r]^qx[l-1];}
struct seg{
	int l,r;
	friend bool operator<(seg aa,seg bb){
		if(aa.r!=bb.r)return aa.r<bb.r;
		return (aa.r-aa.l+1)<(bb.r-bb.l+1);
	}
};
signed main(){
	bool tsA=1,tsB=1,tsC=1;
	int cnt0=0,cnt1=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)tsA=0;
		if(a[i]>1)tsB=0;
		if(a[i]==0)cnt0++;
		if(a[i]==1)cnt1++;
		qx[i]=qx[i-1]^a[i];
	}
	if(k==0&&tsA){//全是1，k=0只能两两一组
		cout<<n/2;
		return 0;
	}
	else if(k<=1&&tsB){//只有0，1，只需要统计
		int lx1=0;
		for(int i=1;i<=n;){
			if(a[i]==a[i+1]&&a[i]==1){
				lx1++;
				i+=2;
			}
			else i++;
		}
		if(k==0)cout<<cnt0+lx1;
		else if(k==1)cout<<cnt1;
		return 0;
	}
	int r=1;
	for(int l=1;l<=n;){
		++ans;
		for(;get(l,r)!=k&&r<=n;r++);//这有点像双指针！
		l=r+1;
		if(l>r)r=l;
	}
	
	//期望得到：#1,#2,#3,#4,#5,#13
//	vector<seg> s;
//	vector<int> ld;
//	for(int l=1;l<=n;l++){
//		int r=l;
//		for(;get(l,r)!=k&&r<=n;r++);
////		le[l]=r-l+1;
//		if(get(l,r)==k)s.push_back({l,r});
//	}
////	sort(le+1,le+n+1);
//	sort(s.begin(),s.end());
//	for(auto sg:s)ld.push_back(sg.l);
//	//线段覆盖问题
//	//可是我忘了！！！！！！！
//	cerr<<s.size()<<endl;
//	for(int i=0;i<s.size();i++){
//		int Lim=s[i].r;
//		int nxtr=upper_bound(ld.begin(),ld.end(),Lim)-ld.begin();//右边那个区间
//		i=nxtr;
//		cerr<<nxtr<<endl;
//		ans++;
//	}
	cout<<ans;
	
	/*
	
	双指针虽然过了#1,#2,#3,#4
	
	但是有问题！
	*/
	
	
	
	//**异或
	//异或就是不进位的加法
	//首先贪心就是：尽量短的区间。
	//只要这个区间满足条件了，就不进行扩展
	//然后是选取端点
	//不是
	//Inracle AK 了
	
	//怎么对于每一个端点，二分查找满足条件的最短区间
	
	//双指针？
	
	//神秘
	//假设ai^后面一坨=k
	//那么后面一坨=a^k!
	//后面一坨是确定的。
	//所以再后面一坨=a^k^ai+1
	/*
	
	观察数据范围，注意到O(nlogn)
	
	前缀异或和？
	
	T4应该是DP
	
	
	*/
//	for(int l=1;l<=n;l++){
//		for(int r=l;r<=n;r++){
//			if(r>=l)cerr<<"["<<l<<","<<r<<"]="<<get(l,r)<<endl;
//		}
//	}
	return 0;
}