#include<bits/stdc++.h>
using namespace std;
int n,ans=0,i,mod=998*244*353;
vector<int> a;
//还需要选择k个数字，前面的数字和为sum ，上一个数字的编号是x 
void f(int k,int sum,int x){
	if (k==0){//如果选取完毕 
		if (sum>a[i]*2) ans=(ans+1)%mod;
		//cout<<"ans+1"<<endl;
		return;
	}
	for(int j=k-1;j<x;j++){
		//printf("还剩%d根木棍，目前遍历到%d的木棍\n",k,a[j]);
		f(k-1,sum+a[j],j);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	a.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	for(i=2;i<n;i++){//遍历最大值
		//cout<<a[i]<<" ";
		for(int j=2;j<=i;j++){//还需要选取的木棍数字 
			f(j,a[i],i);
		}
	}
	printf("%d",ans);
	return 0;
}
