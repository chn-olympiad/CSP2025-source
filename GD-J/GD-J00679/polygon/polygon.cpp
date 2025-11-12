#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int MOD=998244353;
string s;
int ar[N],n;
long long c;
bool arr[N];
void dfs(int ii,int step,int lg,int maxx,int sum){
	if(step==lg+1){
		if(sum>2*maxx){
			c++;
//			cout<<"step:"<<step<<" lg"<<lg<<" maxx"<<maxx<<" sum"<<sum<<endl;
		}return;
	}
	if(ii!=n+1){
		dfs(ii+1,step,lg,maxx,sum%MOD);
		dfs(ii+1,step+1,lg,max(maxx,ar[ii]),(sum+ar[ii])%MOD);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,1,i,INT_MIN,0);
	}cout<<c%MOD;
	return 0;
}
