#include<bits/stdc++.h>
using namespace std;
 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	short t;
	int n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int a,b,c,ans=0,sum=0,x=0,y=0,z=0,d=20001,e=20001,f=20001,g=0,h=0,k=0,l=0,m=0,o=0,p=0,q=0,r=0;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			sum=max(a,max(b,c));
			if(sum==a && x<n/2){
				ans+=sum;
				g=d;
				d=min(sum,d); 
				if(g!=d){
					l=max(b,c);
					if(l==b){
						p=1;
					}
					else{
						p=0;
					}
				}
				x++;
			}
			else if(sum==b && y<n/2){
				ans+=sum; 
				h=e;
				e=min(sum,e);
				if(h!=e){
					m=max(a,c);
					if(m==a){
						q=1;
					}
					else{
						q=0;
					}
				}
				y++;
			}
			else if(sum==c && z<n/2){
				ans+=sum; 
				k=f;
				f=min(sum,f);
				if(k!=f){
					r=max(a,b);
					if(l==a){
						p=1;
					}
					else{
						p=0;
					}
				}
				z++;
			}
			else{
				if(sum==a){
					if(sum>d){
						ans=ans-d+sum;
						d=g;
				    }
				    else if(sum+l>d){
				    	ans=ans-d+sum+l;
				    	d=min(g,sum);
				    	if(p==1){
				    		y++;
				    		e=min(l,e);
						}
						else{
							z++;
							f=min(l,f);
						}
					}
					else{
					    sum=max(b,c);
					    if(sum==b && y<n/2){
				            ans+=sum; 
				            y++;
			            }
			            else{
				            ans+=sum; 
				            z++;
			            }
			        }
				}
				else if(sum==b){
					if(sum>e){
						ans=ans-e+sum;
						e=h;
					}
					else if(sum+m>e){
				    	ans=ans-e+sum+m;
				    	e=min(h,sum);
				    	if(q==1){
				    		x++;
				    		d=min(l,d);
						}
						else{
							z++;
							f=min(l,f);
						}
					}
					else{
					    sum=max(a,c);
					    if(sum==a && x<n/2){
				            ans+=sum; 
				            x++;
			            }
			            else{
				            ans+=sum; 
				            z++;
			            }
			        }
				}
				else{
					if(sum>f){
						ans=ans-f+sum;
						f=k;
					}
					else if(sum+o>f){
				    	ans=ans-f+sum+o;
				    	f=min(k,sum);
				    	if(r==1){
				    		x++;
				    		d=min(l,d);
						}
						else{
							y++;
							e=min(l,e);
						}
					}
					else{
					    sum=max(a,b);
					    if(sum==a && x<n/2){
				            ans+=sum; 
				            x++;
			            }
			            else{
			        	    ans+=sum;
						    y++; 
					    }
				    }
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
