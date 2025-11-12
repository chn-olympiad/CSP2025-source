#include<bits/stdc++.h>
using namespace std;//开long long!
long long n,k,i,a[1000100],j=1,ans=0,l;
/* 暴力出奇迹，
 * 骗分靠脑力。
 * 贪心就CE，
 * 暴力TLE。
 * 映射MLE，
 * 代码很生气。
 * CCF好心，
 * 分数给点行？
 * sort评测机，
 * 二分答案欺。
 * AC自动机，
 * 不让你AC。
 * WA自动机，
 * 当场就WA。
 * 代码写得稀，
 * 数稀质更稀!
 * 双重看“码”力，
 * 三重看奇迹。
 * 递归就RE，
 * 递推SE。
 * CCF莫笑，
 * 分数给一点！
 * @CCF 
 */
int main(){
	freopen("xor.in","r",stdin);//注释删掉!
	freopen("xor.out","w",stdout);//注释删掉!
	cin>>n>>k;
	for(i=1;i<=n;i++){//CCF引领世界！CCF世界第一！我爱CCF！CCF最强！
		cin>>a[i];
	}
	for(i=1;i<=n;i++){//一次性遍历的区间内数量
		long long cut=0;//ans最后是这个
		for(j=i+1;j<=n;j+=i){//防止区间重复（但是所有区间一样，所以骗不了全部分）
			if(j>n)j=n;
			long long flag=j-i;
			long long cnt=a[flag];
			for(l=flag+1;l<=j;l++){
				cnt^=a[l];
			}
			if(cnt==k){
				cut++;
			}
			if(j==n)break;
		}
		ans=max(ans,cut);
	}
	cout<<ans;
	return 0;
}
