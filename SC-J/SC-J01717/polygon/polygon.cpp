#include<bits/stdc++.h>
using namespace std;
int a,b[114514],ans=0; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i];
		if(b[i]==i){
			for(int j=1;j<=i;j++){
				ans+=b[i];
			}
			break;
		}
	}
	cout<<ans;
	return 0;
}