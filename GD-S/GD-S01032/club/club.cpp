#include <bits/stdc++.h>
using namespace std;
long long ans[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t , n , a , b , c;
	long long sum;
	cin >>t;
	for(int i=1;i<=t;i++){
		cin >>n;
		sum=0;
		for(int j=1;j<=n;j++){
			cin >>a>>b>>c;
			sum+=max(a,max(b,c));
		}
		ans[i]=sum;
	} 
	for(int i=1;i<=t;i++){
		cout <<ans[i]<<endl;
	} 
	return 0;
}
