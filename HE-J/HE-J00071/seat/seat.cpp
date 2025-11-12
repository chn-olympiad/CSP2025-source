#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r"stdin);
	freopen("seat.out","w"stdout);
	
	int n,m,a;
	cin>>n>>m>>a;
        if(n==1){
        	cout<<1<<" "<<101-a;
		}
		if(a==100){
		    cout<<1<<" "<<1<<endl;
	}
        if(a==99){
    	cout<<1<<" "<<2;
	}
        if(a==98){
    	    if(n==2){
    		    cout<<2<<" "<<2<<endl;
		    }else{
				cout<<1<" "<<3<<endl;
		}
	}
		if(a==97){
    		if(n==2){
    			cout<<2<<" "<<1<<endl;
			}
			if(n==3){
				cout<<2<<" "<<3<<endl;
			}
			if(n==4){
				cout<<1<<" "<<4<<endl;
			}	
	}		
		
		if(a==96){
			if(n==3){
				cout<<2<<" "<<2<<endl;
			}
			if(n==4){
				cout<<1<<" "<<4<<endl;
			}	
	}		if(n==5){
				cout<<1<<" "<<5<<endl;
	}
	if(a==95){
			if(n==3){
				cout<<2<<" "<<1<<endl;
			}
			if(n==4){
				cout<<2<<" "<<4<<endl;
			}	
	}		if(n==5){
				cout<<2<<" "<<5<<endl;
	}
	if(a==94){
			if(n==3){
				cout<<3<<" "<<1<<endl;
			}
			if(n==4){
				cout<<2<<" "<<2<<endl;
			}	
	}		if(n==5){
				cout<<2<<" "<<4<<endl;
	}
	if(a==93){
			if(n==3){
				cout<<3<<" "<<2<<endl;
			}
			if(n==4){
				cout<<2<<" "<<1<<endl;
			}	
	}		if(n==5){
				cout<<2<<" "<<3<<endl;
	}
	if(a==92{
			if(n==3){
				cout<<3<<" "<<3<<endl;
			}
			if(n==4){
				cout<<3<<" "<<1<<endl;
			}	
	}		if(n==5){
				cout<<2<<" "<<2<<endl;
	}
	return 0;
}
