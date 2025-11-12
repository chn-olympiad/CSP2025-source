#include<iostream>
#include<algorithm> 
using namespace std;
int a[100002][4];
int g[100002];
int t;
int f(int i,int s,int c,int d,int e)
{
	if(c>t/2 or d>t/2 or e>t/2)return 0;if(i>t)return s;
	int l=f(i+1,s+a[i][1],c+1,d,e);
	int m=f(i+1,s+a[i][2],c,d+1,e);
	int n=f(i+1,s+a[i][3],c,d,e+1);
	return max(l,max(m,n));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int h;
	cin>>h;
	
		for (int i=1;i<=h;i++){
		int n;
		cin>>n;
		
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			g[j]=a[j][1];
		}
	
		t=n;if(i<=30){
		cout<<f(1,0,0,0,0)<<endl;
		}
		if(i>30){
			sort(g+1,g+n+1);
			int ggg=0;
			for(int i=n;i>=n-n/2;i++)ggg+=g[i];
			cout<<ggg; 
			
		}
	}
	
}
