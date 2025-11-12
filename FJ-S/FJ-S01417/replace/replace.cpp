#include<bits/stdc++.h>
using namespace std;
int n,q;
string si[200005][2],tj1,tj2;int pi[5000006];
int main() {
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>si[i][0]>>si[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>tj1>>tj2;
		int ans=0;
		for(int j=0;j<=tj1.size();j++)pi[i]=0;
		int r=0;
		for(int j=2;j<=n;j++){
			for(int k=0;k<tj1.size();k++){
				
				for(int j=k;j<k+si[j][0].length()-1;j++){
					
				}
			}
		}
	}
}
/*

*/

