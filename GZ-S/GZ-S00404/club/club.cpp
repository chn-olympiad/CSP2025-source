//GZ-S00404 岑巩县第一中学 袁福彬 
#include<bits/stdc++.d>
using namespace std;
int sum(int joy[])
{
	int loser=0;
	for(int i=1;i<=300001;i++)
	loser=loser+joy[i];
	
	return loser;
}

int main()
{
    int t,n,a[100001][4][4];
    int b[100001][4];
    cin>>t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdont);
	for(int hhh=1;hhh<=t;hhh++)
	{
	    cin>>n;
		int joy[300001]={0},d[n]={0};
		int d1=0,d2=0,d3=0;
		for(int i=1;i<=n;i++){
	        for(int j=1;j<=3;j++){
	            cin>>a[i][j][j];
	            sort(a[i][j],a[i][j]+3)
	            b[i][j]=a[i][j][j];
			}
		}
		
        
		for(int i=1;i<=n;i++){
	        for(int j=1;j<=3;j++){
	        if(a[i][j]>joy[i]){
	        	joy[i]=a[i][j];
	        	d[i]=j
			}
		}
		}
		
		for(int i=1;i<=n;i++){
		if(d[i]==1)d1++;
		if(d[i]==2)d2++;
		if(d[i]==3)d3++;
		}
		if(d1>=n/2)
		{
			for(int i=1;i<=n;i++){
	        for(int j=2;j<=3;j++){
	        if(a[i][j]>joy[i]){
	        	joy[i]=a[i][j];
	        	d[i]=j
			}
		}
		}
		}
		if(d2>=n/2)
		{
			for(int i=1;i<=n;i++){
	        for(int j=1;j<=3;j=j+2){
	        if(a[i][j]>joy[i]){
	        	joy[i]=a[i][j];
	        	d[i]=j
			}
		}
		}
		}
		if(d3>=n/2)
		{
			for(int i=1;i<=n;i++){
	        for(int j=1;j<=2;j++){
	        if(a[i][j]>joy[i]){
	        	joy[i]=a[i][j];
	        	d[i]=j
			}
		}
		}
		}
		cout<<sum(joy[300001])
	}
	return 0;
}
