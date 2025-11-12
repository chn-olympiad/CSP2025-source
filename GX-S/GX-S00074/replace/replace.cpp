#include<bits/stdc++.h>
using namespace std;
long long n,q;
string ns[100010][2],qs[10010][2],j;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>ns[i][0]>>ns[i][1];
	for(int i=1;i<=q;i++)cin>>qs[i][0]>>qs[i][1];
	for(int i=1;i<=q;i++){
		int l=-1,r=-1
		//for( j=qs[i][0].length()-1;j>=0;j--){
		//	if(qs[i][0][j]!=qs[i][1][j]){
	//			l=j;
				//break;
			//}
		//}
		for( j=qs[i][0].length()-1;j>=0;j--){
			if(qs[i][0][j]!=qs[i][1][j]){
				r=j;
				break;
			}
		}
		for(j=1;j<=n;j++){
			if(ns[j][0].length()<(r-l+1))continue;

		}
	}
	
	
	
}
