#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int A=0,B=0,C=0;
		cin>>n;
		int q,w,e;
		int mxa=0,mxb=0,mxab=0;
		for(int i=1;i<=n;i++){
			cin>>q>>w>>e;
			a[i][1]=q;
			a[i][2]=w;
			a[i][3]=e;
			mxa=max(mxa,a[i][1]);
			mxb=max(mxb,a[i][2]);
			
		}	
		
	}
	return 0;
} 
