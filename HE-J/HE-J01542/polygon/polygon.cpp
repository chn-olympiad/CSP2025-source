#include<bits/stdc++.h>
using namespace std;
// 666以为t3考前缀和结果是t4考
int n,l,r,op,mid,a[10010],sum[10010],num;
//等差数列求和 
int cha; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	//二分区间位置查区间和是否大于二倍最大值
	for(int i=3;i<=n;i++){
		l=0;
		r=i;
		op=a[i]*2;
		if(sum[i]<=op){
			continue;
		}
		cout<<sum[i]<<" "<<a[i]<<endl;
		while(r>l){
			mid=(l+r)/2;
			if(sum[i]-sum[mid-1]>op){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		cout<<l<<endl;
		l=l-1;
		cha=l*(l+1)/2;
		num+=cha;
	} 
	cout<<num;
	return 0;
}

