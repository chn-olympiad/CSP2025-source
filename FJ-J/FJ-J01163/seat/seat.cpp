#include<bits/stdc++.h>
using namespace std;  
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[11][11],n,m,b[101];
	cin>>n>>m;     
	for(int i=1;i<=n*m;i++)
		cin>>b[i];
	int ai=b[1];
	for(int i=1;i<=n*m-1;i++)
		for(int j=i;j<=n*m;j++){
			if(b[j]>=b[i]){
				int t=b[j];
				b[j]=b[i];
				b[i]=t;
			}
		}	 
	for(int c=1;c<=m;c++){     
		if(c%2==0)
			for(int r=n;r>=1;r--){          
				a[c][r]=b[(c-1)*n+r];
				if(a[c][r]==ai)
					cout<<c<<" "<<r;
			}
		else
			for(int r=1;r<=n;r++){
				a[c][r]=b[(c-1)*n+r];
				if(a[c][r]==ai)
					cout<<c<<" "<<r;
			}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

