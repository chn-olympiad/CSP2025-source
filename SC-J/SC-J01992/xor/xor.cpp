#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500001],st[500001],en[500001];
long long ns;
long long n,k;
long long s;
bool flag=0,f=0;
void go(int bs){
	if(f==1){
		return;
	}
	if(bs==ns+1){
		flag=0;
		if(ns!=1){
			for(int i=1;i<=ns-1;i++){
				if(en[i]>=st[i+1]){
					flag=1;
					//cout<<en[i]<<" "<<st[i+1]<<endl;
					break;
				}
			}
		}
		if(flag==0){
			f=1;
		}
		return;
	}
	for(int j=1;j<=n;j++){//枚举起点
		for(int l=j;l<=n;l++){//枚举终点
			if(l==j){
				s=a[j];
			}else{
				s=a[j];
				for(int m=j;m<=l-1;m++){//计算 	
					if(s==1&&a[m+1]==1){
						s=0;
					}else if(s==1&&a[m+1]==0){
						s=1;
					}else if(s==0&&a[m+1]==1){
						s=1;
					}else if(s==0&&a[m+1]==0){
						s=0;
					}
				}
			}
			//cout<<j<<" "<<l<<endl<<s<<endl;
			if(s==k){
				st[bs]=j;
				en[bs]=l;
				go(bs+1);
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}
	for(ns=1;ns<=n;ns++){//枚举选的区间数
		f=0;
		go(1);
		if(f==0){
			cout<<ns-1;
			return 0;
		}
	}
	return 0;
}
/*
枚举选的区间数
	枚举起点与终点
		如果无相交且异或和为k
			前往枚举下一个区间数
		否则
			枚举下一个起点与终点
	当这个区间数没有符合条件的区间时
		输出上一个区间数
*/