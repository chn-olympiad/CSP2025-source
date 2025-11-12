#include<bits/stdc++.h>
using namespace std;
long long m,n;
string a;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<m.size();i++){
		for(int j=1;j<m.size();j++){
			for(int k=1;k<m.size();k++){
				cin>>a[i][j][k];
				while(a[i]!=a[i+1]&&a[j]!=a[j+1]){
					cout<<a[k]+a[k+1];
				}
			}
		}
	}
return 0;
}
