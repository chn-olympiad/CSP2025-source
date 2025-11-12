#include<bits/stdc++.h> 
using namespace std;
int c[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		{
			for(int a=0;a<i*j;a++)
			{
				cin>>c[a];
				if(c[0]<c[1])
				{
					swap(c[0],c[1]);
				}
				
			}
		}
	}
	return 0;
}
