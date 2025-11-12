#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
const int N=55000;
int n,a[N],ans,_sum[N],tmp[N];
bool flag[N];

void f(int sum,int t,int num){
	int max=a[t];
	if(num>n)return;
	if(sum>2*max&&num>=3){
		ans++;
		ans%=mod;
		/*for(int i=0;i<num;i++){
			cout<<tmp[i]<<" ";
		}cout<<endl<<sum<<" "<<max<<endl;*/
	}
	for(int i=t;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			tmp[num]=i;
			f(sum+a[i],i,num+1);
			tmp[num]=0;
			flag[i]=0;
		}
	}
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	
	f(0,1,0);
	cout<<ans;
	return 0;}