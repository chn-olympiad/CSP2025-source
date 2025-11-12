#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[7][100000];
int b[7][100000];
int c[7][100000];
int d,e,f,g;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[j][i]>>b[j][i]>>c[j][i];
		}
	}
	for(int j=0;j<t;j++){
		for(int i=0;i<n;i++){
			if(d<=n/2){
			g+=max(max(a[j][i],b[j][i]),max(a[j][i],c[j][i]));
			max(max(a[j][i],b[j][i]),max(a[j][i],c[j][i]))=-1;
			d++;
			}
		}
		cout<<g<<endl;
	}
		
	return 0;
}
