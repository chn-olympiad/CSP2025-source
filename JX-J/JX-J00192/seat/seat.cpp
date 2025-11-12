#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        string a;
        cin>>a[i];
	}
	for(int i=1;i<=n*m-1;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
                		int q=a[i];
                		a[i]=a[j];
                		a[j]=q;
           		}
        	}
	}
	return 0;
}
