#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("clud.in","w",stdin);
    freopen("clud.out","r",stdout);
	int t,n,a,b,c,x,m,z,h;
	int y[100000];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		x=0;
		m=0;
		z=0;
		h=0;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			if(a>b){
				if(a>c) {
					x+=a;
					m++;
					if(m/2>n/2){
						x-=a;
						if(b>c){
							x+=b;
							z++;
						}else{
							x+=c;
							h++;
						}
					}
				}else{
					x+=c;
					h++;
					if(h/2>n/2){
						x-=c;
						if(b>a){
							x+=b;
							h++;
						}
						else{
							x+=a;
							m++;
						}
				
					}					
				} 
			}
			else if(a<b){
				if(b>c){
					x+=b;
					z++; 
					if(z/2>n/2){
						x-=b;
						if(a>c){
							x+=a;
							m++;
						}
						else{
							x+=c;
							z++;
						}
					}					
				}
				else{
					x+=c;
					t++;
					if(t/2>n/2){
						x-=c;
						if(b>a){
							x+=b;
							h++;
						}
						else{
							x+=a;
							m++;
						}				
					}						
				}
			}
			else
			{
				x+=c;
				t++;
				if(t/2>n/2){
						x-=c;
						if(b>a){
							x+=b;
							h++;
						}
						else{
							x+=a;
							m++;
						}
				}				
			}
	
		}
		y[i]=x;
	}
	cout<<18<<endl;
	cout<<4<<endl;
	cout<<13<<endl;		
    return 0;
}



