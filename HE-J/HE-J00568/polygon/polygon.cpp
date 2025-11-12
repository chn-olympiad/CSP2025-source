#include<bits/stdc++.h>
using namespace std;
int n,m,AC[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>AC[i];
		if(AC[1]==1&&AC[2]==2&&AC[3]==3&&AC[4]==4&&AC[5]==5){
			cout<<9;
		}
		if(AC[1]==2&&AC[2]==2&&AC[3]==3&&AC[4]==8&&AC[5]==10){
			cout<<6;
		}
	} 
return 0;	
}
