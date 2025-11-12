//说实话 我真的很不甘心 只要数据中出现重复数字就WA了... 
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[100005];
int b[100005]={};
int vis[100005];
long long ans;

void bianli(int k,int end){
	if(k==end+1){
		int Maxx=0;
		int sum=0;
		for(int i=1;i<=end;i++){
			sum+=b[i];
			if(b[i]>Maxx)
			Maxx=b[i];
		}
		if(sum>2*Maxx){
			ans=ans%998244353;
			ans++;
		}
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(b[k-1]<a[i])
		b[k]=a[i];
		else
		continue;
		bianli(k+1,end);
		b[k]=0;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		int b[100005]={};
		bianli(1,i);
	}
	cout<<ans;
	return 0;
}
