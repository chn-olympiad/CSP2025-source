#include<bits/stdc++.h>
using namespace std;
struct node{
	int a[3];
};
bool cmp(node x,node y)
{
	return (x.a[0]+x.a[1]+x.a[2])>=(y.a[0]+y.a[1]+y.a[2]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		
		int n;
		cin>>n;
        int f[10000]={0};
    	int mt=n/2;
    	int t[1000]={0};
    	vector<node> a;
		for(int i=1;i<=n;i++)
		{	
			int x,y,z;
	    	cin>>x>>y>>z;		
	    	a.push_back({x,y,z});						  			
		}
		
		int m=0;
		if(n==2){
		
	    for(int i=1;i<=3;i++){
	    	for(int j=1;j<=3;j++){
	    		
	    		if(i!=j&&a[0].a[i-1]+a[1].a[j-1]>m){
	    			m=a[0].a[i-1]+a[1].a[j-1];
				}			
			}
		}
		}
	
     	cout<<m;
	}
	return 0;
}
