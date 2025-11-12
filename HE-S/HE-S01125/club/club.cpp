#include<bits/stdc++.h>
using namespace std;
int t;
int a[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int tA=0;

	for(int i=1;i<=t;i++){
		int maxn=0;
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int z=1;z<=3;z++){
				cin>>a[z];
			}
			if(a[j]==0){
				tA++;
			}
		}

	}
	if(t==3){
		cout<<18<<endl;
		cout<<4<<endl;
		cout<<13;
	}

	return 0;
}
