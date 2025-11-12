#include<bits/stdc++.h>
using namespace std;
int a[100001][10],ans[10]={0},tj[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,d,z,x,c[100001],pos;
	cin>>t;
	for(int w=1;w<=t;w++){
		tj[1]=0;
		tj[2]=0;
		tj[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];	
				
		for(int i=1;i<=n;i++){
		    /*d=a[i][1];
			x=a[i][1];
			for(int p=2;p<=3;p++){
				if(a[i][p]>d){
					d=a[i][p];
					pos=p;
				} 
				if(a[i][z]<x) x=a[i][z];
			}
			z=a[i][1]+a[i][2]+a[i][3]-d-x;
			c[i]=d-z;
			tj[pos]++;
			ans[w]+=d;*/
			d=max(max(a[i][1],a[i][2]),a[i][3]);
			x=min(min(a[i][1],a[i][2]),a[i][3]);
			z=a[i][1]+a[i][2]+a[i][3]-d-x;
			c[i]=d-z;
			for(int k=1;k<=3;k++){
				if(a[i][k]==d){
					pos=k;
					break;
				}
				
			}
			tj[pos]++;		
			ans[w]+=d;
			//cout<<ans[w]<<endl;
		}
		//cout<<endl;
		//cout<<tj[1]<<endl;
		//cout<<tj[2]<<endl;
		//cout<<tj[3]<<endl;
		sort(c+1,c+n+1);
		/*for(int i=1;i<=n;i++)
			cout<<c[i]<<" ";
		cout<<endl;*/
		for(int i=1;i<=3;i++){
			
			if(tj[i]>n/2){
				for(int k=1;k<=tj[i]-n/2;k++){
					ans[w]-=c[k];
					//cout<<ans[w]<<endl;
				}
				break;
			}
		}
			
	}
	
	for(int i=1;i<=t;i++)
		cout<<ans[i]<<endl;
	return 0;
}

