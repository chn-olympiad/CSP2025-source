#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> happy1(n+1);
		vector<int> happy2(n+1);
		vector<int> happy3(n+1);
		for(int i=1;i<=n;i++){
			cin>>happy1[i]>>happy2[i]>>happy3[i];
		}
		int total=0;
		for(int i=1;i<=n;i+=2){
			int _add=happy1[i];
			int _bdd=happy2[i];
			int _cdd=happy3[i];
			int _ddd=happy1[i+1];
			int _edd=happy2[i+1];
			int _fdd=happy3[i+1];
			int sum2=_add+_edd;
			int sum3=_add+_fdd;
			int maxn1=max(sum2,sum3);
			int res2=_bdd+_ddd;
			int res3=_bdd+_fdd;
			int maxn2=max(res2,res3);
			int ans2=_cdd+_edd;
			int ans3=_cdd+_ddd;
			int maxn3=max(ans2,ans3);
			int maxn=max(maxn1,max(maxn2,maxn3));
			total+=maxn;
		}
		sort(happy1.begin()+1,happy1.end()+1);
		sort(happy1.begin()+1,happy1.end()+1);
		sort(happy1.begin()+1,happy1.end()+1);
		int tom1=happy1[n]+happy1[n-1];
		int tom2=happy2[n]+happy2[n-1];
		int tom3=happy3[n]+happy3[n-1];
		int counts=max(tom1,max(tom2,tom3));
		cout<<max(total,counts)<<endl;
	}
    return 0;
}

