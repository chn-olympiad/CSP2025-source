#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,k;
int a[N];
int ans;
struct qu{
	int l,r;
}q[N];
//cmp
bool cmp(qu A, qu B){
	return A.r<B.r;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//输入n,k
	cin>>n>>k;	
	//输入a数组
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	//枚举所有可能的左右端点l,r并计算xor，如果这个区间满足就记录下来
	int q_len = 0; 
	for(int len = 1;len<=n;len++){
//		cout<<"len:"<<len<<'\n';
		for(int i = 1;i+len-1<=n;i++){
			int j = i+len-1;
			int xorr = 0;
			for(int k = i;k<=j;k++){
				xorr ^= a[k];
			}
//			cout<<"xorr"<<i<<','<<j<<':'<<xorr<<'\n';
			if(xorr == k){
				q[++q_len].l = i;
				q[q_len].r = j;
//				cout<<"可选区间：["<<i<<','<<j<<']'<<'\n'; 
			}
		}
	} 
	//使用贪心思想(线段覆盖问题)
	//把右端点进行排序
	sort(q+1,q+q_len+1,cmp);
	/*从左往右遍历每个可取区间的左右端点，如果不重叠就选，否则继续遍历下一个
	（记录上一个选的区间右端点来判断是否重叠） 
	*/
	int lstr = q[1].r;
	int ans = 1;
	for(int i = 2;i<=q_len;i++){
		if(q[i].l>lstr){
			ans++;
			lstr = q[i].r;
		}
	}
	//输出答案数
	cout<<ans<<'\n';
	//时间复杂度：O（n^3）期望得分：40 
	//							——10:04梳理完框架 
	//							——10:28 code完，前五个样例已过 
	return 0;
}
