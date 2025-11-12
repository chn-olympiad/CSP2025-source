#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a,b,c;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int sum=1,num=0;
		for(int j=1;j<=n;j++){
			cin>>a;
			if(a>sum){
				sum=a;
			}
			cin>>b;
			if(b>sum){
				sum=b;
			}
			cin>>c;
			if(a>sum){
				sum=c;
			}
			num+=sum;
		}
		cout<<num;
	}
	return 0;
}
