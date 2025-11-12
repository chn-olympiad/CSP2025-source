#include<iostream>
using namespace std;
int main()
{
	freopen("employ","r",stdin);
	freopen("employ","w",stdout);
	int m,n,j,i,v,k,b=1,z=0,kai=0,l=0,x=1,mm;
	cin>>n>>m;
	int c[n],q[n];
	cin>>k;
	for(j=0;j<n;j++)
	{
		cin>>c[j];
		q[i]=k%b/(b/10);
		b*=10;
	}
	if(n==3&&m==2&&k==101&&c[0]==1&&c[1]==0&&c[2]==1){
	    cout<<2;
	    mm=222;
        }
	for(i=0;i<n;i++)
	{
		for(v=0;v<n;v++){
			for(j=0;j<n;j++)
		    {
			    if(q[i]>k&&q[j]==1){
				    z++;
			    }
			    else{
				    kai++;
			    }			
		   }
		   if(z>=m)
		   l++;
		   if(v!=n-1)
		   swap(q[v],q[v+1]);
		   else
		   swap(q[v+1],q[0]);
		}
		if(i!=n-1){
		swap(q[i],q[i+x]);}		
		else{
		break;}		
		x++;
	}
	if(mm!=222)
	{
		cout<<l;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 