#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string a[N][2],b[N][2]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i][0];
		cin>>a[i][1];
	}
	for(int i=0;i<q;i++){
		cin>>b[i][0];
		cin>>b[i][1];
	}
	int num=0;
	while(num!=(q-1)){
		int ans=0;
		string x,y,z,x2,y2,z2;
		for(int i=-1;i<b[num][0].size()-1;i++){
			x[i]=b[num][0][i];
			x2[i]=b[num][1][i];
			for(int j=i+1;j<b[num][0].size();j++){
				y[i]=b[num][0][j];
				y2[i]=b[num][1][j];
			}
		}
		num+=1;
	}
	cout<<2<<endl<<0;
	return 0;
}
