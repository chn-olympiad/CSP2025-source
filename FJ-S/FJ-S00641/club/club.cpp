#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int ans=0,n,r1,r2,r3,p1=0,p2=0,p3=0;//ranking/people 
		cin>>n;
		int pm=n/2;//people max
		for(int j=1;j<=n;j++){
			int a,b,c;
			cin>>a>>b>>c;
			r1=max(max(a,b),c);
			r3=min(min(a,b),c);
			if(r1==a&&r3==b || r1==b&&r3==a) r2=c;
			else if(r1==a&&r3==c || r1==c&&r3==a) r2=b;
			else if(r1==b&&r3==c || r1==c&&r3==b) r2=a;
			
			//what club does j join
		//a
		if(r1==a)
		{
			if(p1<pm){p1++; ans+=a;}
			else{
			  if(r2==b&&p2<pm){p2++; ans+=b;}
		      else{p3++; ans+=c;}
		}
	    }
		//b
		if(r1==b)
		{
			if(p2<pm){p2++; ans+=b;}
			else{
			  if(r2==a&&p1<pm){p1++; ans+=a;}
		      else{p3++; ans+=c;}
		}
	    }
		//c
		if(r1==c)
		{
			if(p3<pm){p3++; ans+=c;}
			else{
			  if(r2==b&&p2<pm){p2++; ans+=b;}
		      else{p1++; ans+=a;}
		    }			
		}		
	    }
		cout<<ans<<endl; 
} 
return 0;
}
