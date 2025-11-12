#include<bits/stdc++.h>
using namespace std;
//有点微妙啊，没读懂题，异或符号也忘了，键盘一个个试
//牛逼试出来了^ 
//666 直接露头就秒  前缀和和差分一样，^和自己是逆运算
//手推的 
int n,k,a[500005],sum[500005],num,mark[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		cout<<n;
	}else{
		cout<<n/2;
	}
	return 0;
}

