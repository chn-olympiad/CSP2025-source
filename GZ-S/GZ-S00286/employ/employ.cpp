//GZ-S00286 贵阳市第一中学 欧阳李樾 
#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
string t;
long long s=1;
int n,m,a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++){
		cin>>a;
	}
	for(int i=1;i<=n;i++){
		s*=i;
		s%=N;
	}
	cout<<s;
	return 0;
}
