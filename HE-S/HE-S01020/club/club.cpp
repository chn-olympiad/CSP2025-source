#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int ans=0;
int cnt1=0,cnt2=0,cnt3=0;
int x,y,z; 
int f[201000];
int a[20100][20];
int w(int x,int y,int z){
	return max(x,max(y,z));
}
    
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
  }
for(int i=1;i<=n;i++){
    x=a[i][1];
    y=a[i][2];
    z=a[i][3];	
    f[i]=w(x,y,z);
    if(f[i]==x){
    	cnt1++; 
	}else if(f[i]==y){
		cnt2++;
	}else if(f[i]==z){
		cnt3++;
	}
	ans+=f[i];
	}
	int d=n/2;
if(cnt1<=d&&cnt2<=d&&cnt3<=d){
cout<<ans<<endl;
}
	

	
	return 0;
} 
