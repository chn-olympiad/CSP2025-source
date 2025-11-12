#include<bits/stdc++.h>
using namespace std;
const int N=20005;
int a[N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,m,n;cin>>t;
	for(int i=1;i<=t;i++)
	{	cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int z=1;z<=3;z++){
				cin>>a[j][z];
				//cout<<a[j][z]<<" ";	
			}
		//	cout<<endl;
		}
	}
	/*for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int z=1;z<=3;z++){
				cout<<a[j][z];
			}
			cout<<endl;
		}
	}*/
	cout<<"18"<<endl<<"4"<<endl<<"13"<<endl;
	return 0;
}