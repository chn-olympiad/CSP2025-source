#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000005];
int b[1000000005];
long long lu=0,bulu=0;
long long ans=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i>=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			if(a[i]==1){
				lu++;
			}
			    else{
				    bulu++;
			    }
			        if(bulu>=a[j]){
				        bulu++;
			        }
			            if(lu>=n){
							ans++;
						}
		}
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}