#include <bits/stdc++.h>
using namespace std;
struct member{
	int g1;
	int g2;
	int g3;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t>0){
		t--;
		int n;
		cin>>n;
		member a[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i].g1>>a[i].g2>>a[i].g3;
		}
		int s=n/2;
		int sum=0;
		for(int i=1;i<=n;i++){
			int maxn=max(max(a[i].g1,a[i].g2),a[i].g3);
			sum+=maxn;
		}
		cout<<sum<<endl;
	}
	return 0;
}
