#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
bool vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]==k){
			cnt++;
			vis[i]=1;
		}
		int j=0;
		int b[N];
		while(a[i]>1){
			j++;
			b[j]=a[i]%2;
			a[i]/=2;
		}
		j+=1;
		b[j]=a[i];
		a[i]=0;
		int num=0;
		for(int p=j;p>=1;p--){
			num=b[p];
			for(int q=0;q<p-1;q++){
				num*=10;
			}
			a[i]+=num;
		}
	}
	int b[N];
	for(int p=1;p<n;p++){
		int i=p;
		int sum=1;
		for(i=1;i<=n;i++){
			if(vis[i]==1){
				break;
			}
			while(a[i]){
				while(a[i+1]){
					if(a[i]%2==a[i+1]%2) b[sum]=1;
					else b[sum]=0;
					a[i]/=10;
					a[i+1]/=10; 
					sum++;
				}
			}
			if(a[i]!=0||a[i+1]!=0) b[sum]=0;
			else sum--;
			a[i+1]=0;
			int num=0;
			for(int t=sum;t>=1;t--){
				num=b[t];
				for(int q=0;q<t-1;q++){
					num*=10;
				}
				a[i+1]+=num;
			}
		}
		int f=0;
		int num=0;
		while(a[i]){
			int u=a[i]%2;
			if(u!=0&&num!=0){
				for(int t=1;t<=num;t++){
					u*=2;
				}
			}
			if(u==1&&num==0) u++;
			f+=u;
			a[i]/=10;
			num++;
		}
		if(f==k) cnt++;
	}
	cout<<cnt;
	return 0;
}


