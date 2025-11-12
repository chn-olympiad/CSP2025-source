#include<bits/stdc++.h> 
using namespace std;
long long q[100010][3],j[100010],x,n,ans;

int main(){
	freopen("ciub.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>x;
	while(x--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>j[i]>>q[i][2]>>q[i][3];	
		}
		sort(j+1,j+1+n);
		for(int i=n;i>n/2;i--){
			ans+=j[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
