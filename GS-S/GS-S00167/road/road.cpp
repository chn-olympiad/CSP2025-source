#include<bits/stdc++.h>
using namespace std;
int max(int a,int b,int c){
	if(a>b && a>c){
		return a;
	}
	if(b>a && b>c){
		return b;
	}
	if(c>a && c>b){
		return c;
	}
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,n,maxb;
	int a[100005][5];
	int maxa[100005];
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
				maxa[j]=max(a[j][1],a[j][2],a[j][3]);
			}
			maxb=maxa[j]+maxa[j-1];
		}
		cout<<maxb<<endl;
	}
	return 0;
}
