#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n][m];
	int b[n*m+5];
	for(int i=1;i<=n*m;i++) cin>>b[i];
	int R=b[1];
	sort(b+1,b+n*m+1);
	int cnt=n*m; 
	for(int i=1;i<=m;i++)
	{
		if(i%2==0){
			for(int j=n;j>=1;j--)
			{
				a[j][i]=b[cnt];
			    cnt--;
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
	        {
	    	a[j][i]=b[cnt];
			cnt--; 
		    }
		}
		
	}
	for(int i=1;i<=m;i++)
	    for(int j=1;j<=n;j++)
	    {
	    	cout<<a[j][i]<<" ";
	        if(a[j][i]==R) cout<<i<<" "<<j;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

