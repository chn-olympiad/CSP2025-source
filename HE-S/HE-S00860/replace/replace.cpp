#include<bits/stdc++.h>
using namespace std;

int n,q;
const int QAQ=2e5+19;
string s[QAQ][3];
#define ull unsigned long long
#define mk make_pair
map<pair<ull,ull>,int> cun;
const ull zhi=1811145141;
ull haxi(string s)
{
	ull ans=0;
	for(int i=0;i<s.size();i++)
		ans=ans*zhi+(ull)s[i]*233;
	return ans;
}
const int ovo=5e6+19;
ull qz1[ovo],qz2[ovo];
int siz[ovo];
vector<int> ke;
ull ci[ovo];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ci[0]=1;
	for(int i=1;i<=5000000;i++) ci[i]=ci[i-1]*zhi;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		siz[s[i][1].size()]++;
		if(siz[s[i][1].size()]==1) ke.push_back(s[i][1].size());
		cun[mk(haxi(s[i][1]),haxi(s[i][2]))]++;
	}
	sort(ke.begin(),ke.end());
//	cout<<"            ";
//	for(int x:ke) cout<<x<<' ';
//	cout<<'\n';
	
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		if(t1.size()==0||t1.size()!=t2.size()) cout<<"0\n";
		else
		{
			int l=0,r=t1.size()-1;
			while(t1[l]==t2[l]) l++;
			while(t1[r]==t2[r]) r--;
			qz1[0]=(ull)t1[0]*233;
			qz2[0]=(ull)t2[0]*233;
			for(int i=1;i<t1.size();i++)
			{
				qz1[i]=qz1[i-1]*zhi+(ull)t1[i]*233;
				qz2[i]=qz2[i-1]*zhi+(ull)t2[i]*233;
			}
			for(int i=0;i<=l;i++)
			{
				int duan=r-i+1;
				int kai=lower_bound(ke.begin(),ke.end(),duan)-ke.begin();
				for(int p=kai;p<ke.size();p++)
				{
					int j=i+ke[p]-1;
					if(j>=t1.size()) continue;
					ull o1,o2;
					if(i==0) o1=qz1[j],o2=qz2[j];
					else o1=qz1[j]-qz1[i-1]*ci[j-i+1],o2=qz2[j]-qz2[i-1]*ci[j-i+1];
					ans+=cun[mk(o1,o2)];
				}
			}
			cout<<ans<<'\n';
		}
	}
	
	
	
	return 0;
}
/*

注意空间 2GB


只能操作一次啊！
感觉是哈希之类的 
 
等待思考 1 ：大样例大多数输出为 0，也许可以打一个依赖答案复杂度的东西 

显然一个枚举区间的 L^2 做法，20pts。 

能放字典树上匹配吗？ q*l 的貌似？AC 自动机可以做吗？ 

算了推点性质：
1. （错了错了）首尾相同的部分我们可以直接舍弃掉 。（好像不行 
2. 注意到替换二元组相同但是子串位置不同当且仅当有 没用的 二元组，这个要特殊判断。
3. 我们跑出 t1、t2 不同的最大区间 [L,R]，然后看
4. 询问的和 <=5e6 吗？那我 O(L) 做就可以了？
5. 我们平衡复杂度需要从 n、L1 和 q、L2 的角度平衡。
6. 空间 2GB？？？bitset 吗？ 
 

 
A 的特殊性质可以直接？ 




*/
