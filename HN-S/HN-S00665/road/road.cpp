#include<bits/stdc++.h>
using namespace std;
int qqq[1000001],uiui[1000001],f[20];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>qqq[i]>>qqq[i]>>qqq[i];
	}
	for(int i=0;i<k;i++){
		cin>>f[i];
//		cout<<f[i]<<'\n';
		for(int j=0;j<n;j++){
			cin>>uiui[j];
		}	
	}
	sort(f,f+k);
///	for(int i=0;i<k;i++)cout<<f[i];
	cout<<f[0];
	return 0;
}
