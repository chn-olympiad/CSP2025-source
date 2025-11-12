#include<fstream>
using namespace  std;
ifstream cin("polygon.in");
ofstream cout("polygon.out");
int n,a[5005]={};
long long num=0;
void dfs(int k,int sum,int mu){
	if(mu>=3){
		num++;
	}
	for(int j=k+1;j<=n;j++){
		if(a[j]<sum||mu<3){
			sum+=a[j];
			dfs(j,sum,mu+1);
			sum-=a[j];
		}
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		dfs(i,a[i],1);
	}
	cout<<num%998244353;
	cin.close();
	cout.close();
	return 0;
} 
