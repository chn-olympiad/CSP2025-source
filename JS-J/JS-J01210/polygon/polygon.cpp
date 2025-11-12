#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<int> a;
bool flag;
int n;
long long ans=0;
long long solve(int b,int e){
	long long cnt=0;
	for(int i=b;i<=e;i++){
		cnt+=a[i];
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int number;
		cin>>number;
		a.push_back(number);
		if(number!=1) flag=true;
	}
	sort(a.begin(),a.end());
	if(n==3){
		if(a[0]+a[1]>a[2]){
			cout<<1<<endl;
		}
		else cout<<0<<endl;
	}
	else if(!flag){
		for(int i=3;i<=n;i++){
			long long ansn=0;
			int cnt=1;
			for(int j=n;j>i;j--){
				cnt*=j;
			}
			ansn+=cnt;
			cnt=1;
			for(int j=1;j<=n-i;j++){
				cnt*=j;
			}
			ansn/=cnt;
			ans+=ansn;
			ans%=998244353;
		}
		cout<<ans<<endl;
	}
	else{
		for(int i=n-1;i>=2;i--){
			int maxn=a[i]*2;
			for(int j=2;j<=i;j++){
				for(int k=i-1;k-j>=0;k--){
					//cout<<"max:"<<a[i]<<"num:"<<j<<"other: from"<<k-j+1<<"to"<<k<<"="<<solve(k-j+1,k)<<endl;
					if(solve(k-j+1,k)+a[i]<=maxn){
						long long ansnnn=solve(k-j+1,k)+a[i];
						int q=k+1;
						while(ansnnn-a[k-j+1]+a[q]>maxn&&q<=j){
							ans++;
							ans%=998244353;
							q++;
						}
						break;
					}
					else{
						ans++;
						ans%=998244353;
					}
				}
			}
		}
		cout<<ans*3<<endl;
	}
	return 0;
}
