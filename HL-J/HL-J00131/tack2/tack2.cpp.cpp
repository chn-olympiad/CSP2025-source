#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int js[110];
int main(){
	int cnt1=1,cnt2=1,cj=0,m1,n1;
	int n,m;
	cin>>n>>m;
	int cnt3=110;
	for(int i=1;i<=n*m;i++){
		cin>>js[i];
		cj=js[1];
	}
	sort(js+1,js+110+1);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				a[i][j]=js[cnt3];
				if(js[cnt3]==cj){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt3--;
			}	
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				a[i][j]=js[cnt3];
				if(js[cnt3]==cj){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt3--;
			}	
		}
		
	}
	
	return 0;
}
