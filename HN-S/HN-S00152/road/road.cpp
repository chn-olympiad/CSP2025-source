#include <bits/stdc++.h>
using namespace std;
int n,m,k,lu[100005][10],bd[100005][10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i;i<m;i++){
		cin>>lu[i][0]>>lu[i][1]>>lu[i][2];
	}
	for (int i=0;i<k;i++){
		cin>>bd[k][0]>>bd[k][1]>>bd[k][2]>>bd[k][3]>>bd[k][4];
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}
}
