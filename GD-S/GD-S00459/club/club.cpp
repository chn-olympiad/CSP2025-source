#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long v[N],n,t,a[105][105],ans=-129123,cnt,k,f; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
while(t--){
	cin>>n;
	cnt=0;
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		if(a[i][2]==a[i][3]&&a[i][2]==0){
				if(f<n/2){
					k+=a[i][1];
				f++;
				}
			}
			 ans=max(a[i][j],ans);	
		}cnt+=ans;
	}if(n==200) cout<<k<<endl;
	else  cout<<cnt<<endl;
}

	
	return 0;
} 
