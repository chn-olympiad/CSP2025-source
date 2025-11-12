#include <bits/stdc++.h>
using namespace std;
long long f[100010],t,n;
struct Stu{
	long long a1,a2,a3;
}stu[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>stu[i].a1>>stu[i].a2>>stu[3].a3;
		}
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=n-i&&j<=n/2;j++){
				for(int k=1;k<=n-i-j&&k<=n/2;k++){
					f[i]+=max({stu[i].a1,stu[i].a2,stu[i].a3});
				}
			}
		}
		cout<<f[n/2]<<"\n";
	}
	return 0;
}