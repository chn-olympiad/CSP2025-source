#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,maxn1,maxn2;
	int a[10001][4];
	int b[4]={0,0,0,0};
	cin>>t;
	int n,num=0;
    while(t--){
    	for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
            	cin>>a[i][j];
			}	
		}
		sort(a,a+n);
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
	}
	return 0;
}
