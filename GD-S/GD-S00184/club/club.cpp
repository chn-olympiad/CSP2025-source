#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,x,y,z,ans;
	int t;
	cin>>t;
	while(t--){
		x=0,y=0,z=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>b && a>c){
				if(x<n/2){
					ans+=a;
					x++;
				}
				else if(b>c && y<n/2){
					ans+=b;
					y++;
				} 
				else if(z<n/2){
					ans+=c;
					z++;
				}
			}
			if(b>a && b>c){
				if(y<n/2){
					ans+=b;
					y++;
				}
				else if(a>c && x<n/2){
					ans+=a;
					x++;
				} 
				else if(z<n/2){
					ans+=c;
					z++;
				}
			}
			if(c>a && c>b){
				if(z<n/2){
					ans+=c;
					z++;
				}
				else if(a>b && x<n/2){
					ans+=a;
					x++;
				} 
				else if(b<n/2){
					ans+=b;
					y++;
				}
			}
		}
		 cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
