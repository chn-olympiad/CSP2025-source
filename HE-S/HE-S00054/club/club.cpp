#include<bits/stdc++.h>
using namespace std;
int main(){
	preopen("club.in","w",stdin);
	preopen("club.out","r",stdout);
	int t;
	int b =0;
	cin>>t;
	int st;
	int cnt=0;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=t;k++){
				cin>>st;
				if(st>b) b=st;
			}
			cnt+=b;

		}
		cout<<cnt<<endl;
		cnt=0;
	}
}
