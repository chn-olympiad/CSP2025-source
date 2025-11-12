#include<iostream>
#include<cstdio>
using namespace std;
int n,k;	
long long a[500010];
int d[500010];
int f[500010];
int main(){
									//文件读写
									//数据范围 
									//输出格式 
									//别挂分pls 
									//一等pls 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	int l,r;
	int sum=0;
	
		
		for(r=n;r>=1;r--){
		sum=0;
			for(l=r;l>=1;l--){
				sum=sum^a[l];
				if(sum==k){
					d[r]=l;
					break;
			}
		}
	}
	for(i=1;i<=n;i++){
		f[i]=f[i-1];
		if(d[i]){
			f[i]=max(f[i],f[d[i]-1]+1);
		}
	}
	cout<<f[n]<<"\n";
	//for(i=n;i>=1;i--)cout<<d[i]<<' ';
	return 0;
} 


