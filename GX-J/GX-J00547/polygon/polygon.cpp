#include<bits/stdc++.h>
using namespace std;
	int n,m,li,ans=0;                
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=m;i++){
		if(li>2*li){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
