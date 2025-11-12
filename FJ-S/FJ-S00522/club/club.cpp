#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//struct ren{
//	int a1,a2,a3;
//}r[1123456];
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	int t,n;
	int a1,a2,a3;
	int ans=0;
	cin>>t;
	for(int z=0;z<t;z++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			if(a1>a2&&a1>a3){
				ans+=a1;
			}else if(a2>a1&&a2>a3){
				ans+=a2;
			}else{
				ans+=a3;
			}
		}
		cout<<ans;
	}
	return 0;
}
