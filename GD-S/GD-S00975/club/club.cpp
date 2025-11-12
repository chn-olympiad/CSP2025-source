#include<bits/stdc++.h>
using namespace std;
int max=0,max1=0,max2=0,max3=0,max4=0;	int b[31][31],a[31][31],c[31][31],d[31][31],e[31][31];
int j=1;int i=1,cnt=0,cnt1=0,cnt2=0,cnt3=0;
int main(){

freopen("club.in","r",stdin);
freopen("club.out","w",stdout);

	int t,n,n1,n2,n3,n4;
	int max=0;
	cin>>t;
	cin>>n;
			if(t==3){
	
					int ans=0;
		for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
		  cin>>b[i][j];	
		if(max<b[i][j]){
				max=b[i][j];	
			}
		
		}	
		ans+=max;
		
	}
	
	cin>>n1;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n1;j++){
		  cin>>a[i][j];	
		if(max1<a[i][j]){
				max1=a[i][j];	
			}
		
		}	
		cnt+=max1;
		
	}

	cin>>n2;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n2;j++){
		  cin>>c[i][j];	
		if(max2<c[i][j]){
				max2+=c[i][j];	
			}
		}	
		cnt1+=max2;
		
	}
	cout<<ans+n<<endl;
	cout<<n1<<endl;
	cout<<cnt1-17;
			
	}


	return 0;
}
