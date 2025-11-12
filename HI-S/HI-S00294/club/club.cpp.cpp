#include<bits/stdc++.h>
using namespace std;
	int a[10005],b[10005],c[10005],ans1=0;
	int w;
	int w1(int i,int j,int l,int ans){
		if(i+j+l==w*2){
		
			ans1=max(ans1,ans);
			
	    } 
		if(i<w){
			i++;
		
		 return w1(i,j,l,ans+=a[i+j+1]);
		}
		if(j<w){
			j++;
			
		return w1(i,j,l,ans+=b[i+j+l]);
		}
		if(l<w){
			l++;
			
		return w1(i,j,l,ans+=c[i+j+l]);
		}
	   
	}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m;
	cin>>n;
	while(n--){
		int s;
		cin>>s;
		 w=s/2;
	for(int i=1;i<=s;i++)
	cin>>a[i]>>b[i]>>c[i];
		if(s==2){
			int ans=0;
		
		ans=max(ans,a[1]+b[2]);
		ans=max(ans,a[1]+c[2]);
		ans=max(ans,b[1]+c[2]);
		ans=max(ans,a[2]+b[1]);
		ans=max(ans,a[2]+c[1]);
		ans=max(ans,b[2]+c[1]);
			
			cout<<ans<<endl;
		}	
	else{
		w1(0,0,0,0);
		cout<<ans1<<endl;
		ans1=0;
}
	}


return 0;
}
