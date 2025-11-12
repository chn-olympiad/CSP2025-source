#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
	map<int,int>a;
int main(){
    int t;
	freopen("club.cpp","r",stdin);
	freopen("club.cpp","w",stdout);
	int n,ans[105];
	cin>>t;
	while(t--){
		for(int i=0;i<=t;i++){
			cin>>n;
			for(int j=0;j<=i;j++){
				cin>>a[j];
				if(a[j]>n/2)continue;
				else ans[j]=ans[j]+a[j];
			}
		}
	}
    for(int i=0;i<=t;i++){
		cout<<ans[i]<<endl;
	}
return 0;
}  