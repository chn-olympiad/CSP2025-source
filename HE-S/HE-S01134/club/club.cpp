#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
	{
		int n;
		cin>>n;
		int a[10],num=0,sum=0,q=0,w=0;
		for(int j=1; j<=n; j++){
			cin>>a[1]>>a[2]>>a[3];
			if(a[1]>a[2]){
				if(a[1]>a[3]){
					num++;
					w+=a[1];
				}
				else{
					q++;
					w+=a[3];
				}
			}
			else{
				if(a[2]>a[3]){
					sum++;
					w+=a[2];
				}
				else{
					q++;
					w+=a[3];
				}
			}
		}
		if(num<=n/2){
			if(sum<=n/2){
				if(q<=n/2){
					cout<<w;
				}
			}
		}
	}
	
	
	return 0;
}
