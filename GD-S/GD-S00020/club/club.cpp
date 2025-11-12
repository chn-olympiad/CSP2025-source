#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int f;
struct mm{
	int v,club;
};
mm p[100005][13];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		f=n/2;
		//cout<<f<<endl;
		for(int i=0;i<n;i++){
			
			
			cin>>p[i][0].v>>p[i][1].v>>p[i][2].v;
			
			p[i][4].v=0;
			
		}int maxx=0;
		for(int j=0;j<=2;j++){
			
			int c1=0,c2=0,c3=0;
			for(int i=n-1;i>=0;i--){
			
			
				
				if(p[i][4].v==0){
					int ma=0;
					if(c1<f&&c2<f&&c3<f)ma=max(p[i][abs(3-j+1)%3].v,max(p[i][abs(3-j+2)%3].v,p[i][abs(3-j)%3].v));
					if(c1>=f) ma=max(p[i][abs(3-j+2)%3].v,p[i][abs(3-j)%3].v);
					else if(c2>=f) ma=max(p[i][abs(3-j+1)%3].v,p[i][abs(3-j)%3].v);
					else if(c3>=f) ma=max(p[i][abs(3-j+1)%3].v,p[i][abs(3-j+2)%3].v);
					
					
					
					if(c1<f&&p[i][abs(3-j+1)%3].v==ma){
						sum+=p[i][abs(3-j+1)%3].v;c1++;
						
					}
					if(c2<f&&p[i][abs(3-j+2)%3].v==ma){
						sum+=p[i][abs(3-j+2)%3].v;c2++;
							
				
					}
					if(c3<f&&p[i][abs(3-j+3)%3].v==ma){
						sum+=p[i][abs(3-j+3)%3].v;c3++;
							
					}
				
					p[i][4].v=1;
				}
		
			}maxx=max(maxx,sum);
		}
		cout<<maxx<<endl;
		
		
	}
	return 0;
}
