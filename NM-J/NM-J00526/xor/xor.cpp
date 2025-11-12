#include<iostream>
#include<algorithm>
/*
需要找出最多的权值为k的不相交区间 
考虑使用前缀和
可以发现 若a^b=c,则c^a=b,c^b=a
我tm是人类啊想了半个小时
那么前缀和秒了
n<=50000 k<=2^20
如果我们选了短的区间大概会比长区间更优 
因为我们不仅可以选择选了长区间的区间 
还有被长区间包含的区间 
写个n^2看看能不能过10000的数据 
可以的话起码有暴力分 写一个数组收集一下用过的节点 
 ...
起码样例是过了，先检查检查代码再去看t4能不能水点分
* may 60pts
* CSP-J2025 T3 ylqg
*/ 
using namespace std;
long long q(int x,int y,int l[200006]){
	return (l[y] ^ l[x-1]);
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long ans=0;
	cin>>n>>k;
	int l[200005]= {0};
	cin>>l[1];
	for(int i=2;i<=n;i++){
		long long t;
		cin>>t;
		l[i] = (l[i-1] ^ t); 
	}
	int p[200005]={0};
	int ps=0,fl=0; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int q=0;q<=ps;q++){
				if(p[q]<=i&&p[q]>=j){
					//cout<<"开始寻找是否被占用\n";
					fl=1;
					break;	
				}
			}
			if(fl==1){
				fl=0;
				//cout<<"区间被占用\n";
				continue;
				
			}else{
				//cout<<"可以选择 ";
				if(q(j,i,l)==k){
				//printf("选择了区间%i,%i\n",j,i);
					ans++; 
					for(int z = j;z<=i;z++){
						p[ps] = z;
						ps++;
					}	
				}
				//cout<<ps<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
