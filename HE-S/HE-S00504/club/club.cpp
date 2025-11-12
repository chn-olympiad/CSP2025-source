#include<bits/stdc++.h>
using namespace std;
int T;                             
bool cmp(int x,int y){
	return x>y;
}                                 
int main(){
	freopen("club.in","r",stdin);                          
	freopen("club.out","w",stdout);                           
	cin>>T;                                      
	while(T--){                                                                                        
		int n,ans=0,cx,cy,cz,p[50010],q[50010],r[50010],x[50010],y,z;                                              
		cin>>n;                                                                                               
		for(int i=1;i<=n;i++){                                                                                  
			cin>>p[i]>>q[i]>>r[i];		
			ans+=max(p[i],max(q[i],r[i]));                                                                          
		}                                                                                                          
		cout<<ans<<endl;
	}                                                                                                            
	return 0;                                                                                                   
}	

