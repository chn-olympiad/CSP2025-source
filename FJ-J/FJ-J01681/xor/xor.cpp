#include<iostream>
#include<map>
using namespace std;
map<int,int>mp;
int n,k;
int num[500000];
int icnt[500000];
bool cnt[500000][30],bit[500000][30];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int mn=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		icnt[i]=icnt[i-1]^num[i];
//		cout<<(num[i]^k)<<endl;
		if(mp[icnt[i]^k]!=0&&mp[icnt[i]^k]>=mn){
//			cout<<num[i]<<endl;
//			cout<<mp[icnt[i]^k]<<' '<<i<<endl;
			ans++;
			mn=i;
		}
		else if(num[i]==k){
//			cout<<num[i]<<endl;
//			cout<<i-1<<' '<<i<<endl;
			ans++;
			mn=i;
		}
		else if(icnt[i]==k&&mn==0){
//			cout<<num[i]<<endl;
//			cout<<0<<' '<<i<<endl;
			ans++;
			mn=i;
		}
		mp[icnt[i]]=i;
	}
	cout<<ans;
	return 0;
}

