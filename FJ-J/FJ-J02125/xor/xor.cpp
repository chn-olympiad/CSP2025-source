#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0; bool opt=true; char c=getchar();
	while(!isdigit(c)){ if(c=='-')opt=false; c=getchar(); }
	while(isdigit(c)){ x=x*10+c-48; c=getchar(); }
	return opt?x:-x;
}
inline void write(int x){
	static int s[20]; int top=0;
	if(x<0)putchar('-'),x=-x;
	if(x==0){ putchar('0'); return; }
	while(x){ s[++top]=x%10; x/=10; }
	while(top>0){ putchar(s[top--]+48); }
}
const int maxn = 5e5 + 5;
int a[maxn]; 
bool cmp(const pair<int,int>& p,const pair<int,int>& q){
	if(p.second!=q.second){
		return p.second<q.second;
	}
	return p.first<q.first;
} // 按右端点排序 
int main(){
// 试图使用暴力求区间(O(n^2))+贪心(O(nlogn)瓶颈排序)选区间拿(pian)到前12个测试点 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=read(),k=read();
	for(int i=0;i<n;i++){ // 正常读入 
		a[i]=read();
	}
	vector<pair<int,int> > result;
	result.reserve(n);
	for(int i=0;i<n;i++){ // 暴力获得区间 
		int XorSum=0;
		for(int j=i;j>=0;j--){
			XorSum^=a[j];
			if(XorSum==k){
				result.push_back(make_pair(j,i));
				break;
			}
		}
		// 255何意味	 
	}
	// 贪心求最多区间个数 
	sort(result.begin(),result.end(),cmp); // 排序 
	int last=0,ans=0; // 记录最右边的区间的右端点以及答案 
//	for(auto& [l,r] : result){ // 遍历所有区间 
	//不好！不能用  48	12 F:\FJ-J02125\xor\xor.cpp [Warning] structured bindings only available with '-std=c++17' or '-std=gnu++17'
	for(auto& p : result){
		int l=p.first,r=p.second;	
//		cout<<l<<" "<<r<<'\n';
		if(l>=last){ // 可以选就选 
			last=r;
			ans++;
		}
	}
	write(ans); // 输出答案 
	return 0;
}
// 贪心？DP？ST表(我在说什么)？
// 总的来说T1T2橙题  T3T4绿题(猜的)  难度比较正常(至少没有蓝题)  
