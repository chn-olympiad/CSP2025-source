#include<bits/stdc++.h>
using namespace std;
long long t,n[10],a1[5][100005],a2[5][100005],a3[5][100005],s;
int main(){
  	freopen("club.in","r",stdin);
  	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a1[i][j]>>a2[i][j]>>a3[i][j];
			s+=max(a1[i][j],a2[i][j],a3[i][j]);
		}
		cout<<s<<endl;
	}
	return 0;
}
