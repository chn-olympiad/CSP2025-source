#include<bits/stdc++.h> 
using namespace std;
int s[1000000];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	int m;
	cin>>m;
	long long d;
	for(int i=0;i<m;i++){
		
		d=0;
		
		int n;
		cin>>n;
		int p=n/2;
		int x=0,y=0,z=0;
		int he[n+1];
		
		
		for(int j=0;j<n;j++){
			int a=0,b=0,c=0;
			
			
			
			
			
			if(x<p&&y<p&&z<p){
			
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				he[j]=a;
				x++;
			}
			else if(b>=a&&b>=c){
				he[j]=b;	
				y++;
			} 
			else if(c>=b&&c>=a){
				he[j]=c;
				z++;
			}






			}else if(x>=p){
				int a=0,b=0,c=0;
				cin>>a>>b>>c;
				if(b>=c){
					he[j]=b;
					y++;
				}else if(c>=b){
					he[j]=c;	
					z++;
				}





			}else if(y>=p){
				int a=0,b=0,c=0;
				cin>>a>>b>>c;
				if(a>=c){
					he[j]=a;
					x++;
				}else if(c>=a){
					he[j]=c;	
					z++;
				}
				
				
				
				

			}else if(z>=p){
				int a=0,b=0,c=0;
				cin>>a>>b>>c;
				if(a>=b){
					he[j]=a;
					x++;
				}else if(b>=a){
					he[j]=b;	
					y++;
				}
	
			}
			
			
			
	}
	
	
		sort(he,he+n+1);
		for(int k=n-1;k>=0;k--){
			d+=he[k];
		}
		s[i]=d;
	//	cout<<d;
	}
	for(int i=0;i<m;i++){
		cout<<s[i]<<endl;
	}
			
	
	return 0;
}
\
