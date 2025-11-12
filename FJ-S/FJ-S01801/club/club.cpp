#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;t++){
		int n;
		cin>>n;
		int a=0,max=n/2;
		
		for(int j=1;j<=n;j++){
			int bu[5];
			for(int l=1;l<=3;l++){
				cin>>bu[l];
			}
			if(bu[1]>bu[2]&&bu[1]>bu[3]){
				a+=bu[1];
			}
			else if(bu[2]>bu[1]&&bu[2]>bu[3]){
				a+=bu[2];
			}
			else if(bu[3]>bu[2]&&bu[3]>bu[1]){
				a+=bu[3];
			}
		}
		cout<<a<<endl;
	}
	return 0;
}
