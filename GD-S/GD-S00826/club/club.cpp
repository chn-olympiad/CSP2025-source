#include<bits/stdc++.h>
using namespace std;
int n,t,m[100005][5],x=-1,ans=0,z=0,v=0,b=0,e=0,f=0,tp=0,p=0,a[100005];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int r = 1;r<=t;r++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=3;j++){
				cin>>m[i][j];
			} 
			if(m[i][2]==0) tp++;
			if(m[i][3]==0) p++;
		}
	    for(int i = 1;i<=n;i++){
		    for(int j = 1;j<=3;j++){
		        if(tp==0&&p==0){
		       	    a[i] = m[i][1];
		       	    continue;
			    }
			    if(p==0){
			    	a[i] = max(m[i][1],m[i][2]);
			    	continue;
				}
		        else{
		       	    if(z>n/2){
			   	        if(m[i][2]>m[i][3]) x = m[i][2];
			   	        else x = m[i][3];
			        }  
			        if(v>n/2){
			   	        if(m[i][1]>m[i][3]) x = m[i][1];
			   	        else x = m[i][1];
			        }
			        if(b>n/2){
			   	        if(m[i][1]>m[i][2]) x = m[i][1];
			   	        else x = m[i][2];
			        }
			        else{
			   	        if(m[i][j]>x){
			   	            x = m[i][j];
			   	            e = j;
					    }
			        }
			    } 
		    }
		    if(tp==0&&p==0){
		       	sort(a+1,a+n+1);
		       	for(int i = n/2+1;i<=n;i++) ans+=a[i];
			}
			else if(p==0){
		       	sort(a+1,a+n+1);
		       	for(int i = n/2+1;i<=n;i++) ans+=a[i];
			}
			else{
				if(e==1) z++;
			    if(e==2) v++;
			    if(e==3) b++;
		        ans+=x;
		        x = 0;
			}
	    }
	    cout<<ans;
	    ans = 0;	
	}
	return 0;
} 
