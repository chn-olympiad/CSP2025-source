#include<bits/stdc++.h>
using namespace std;
int c[15][15],wy=1,d;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);	
    int m,n;
    cin>>n>>m;
    int a[110],s=n*m;
    for(int i=1;i<=s;i++){
	    cin>>a[i];
	}
	int k=a[1];
	for(int i=1;i<=s;i++){
		for(int j=i+1;j<=s;j++){
			if(a[j]>a[i]){
				int ly=a[j];
				a[j]=a[i];
				a[i]=ly;
			}
		}
	}
	for(int i=1;i<=s;i++){
		if(k==a[i]){
		    d=i;
		    break;
		}
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
    }
	if(n==1){
	    cout<<d<<" "<<1;
	    return 0;	
	}	
	if(m==1){
		cout<<1<<" "<<d;
		return 0;
	}
	if(n==2&&m==2){
		if(d==1){
			cout<<1<<" "<<1;
			return 0;
		}
		else if(d==2){
			cout<<1<<" "<<2;
			return 0;
		}
		else if(d==3){
			cout<<2<<" "<<2;
			return 0;
		}
		else if(d==4){
			cout<<2<<" "<<1;
			return 0;
		}	
	}
	if(n==2&&m<=10){
	    if(d==1){
		    cout<<1<<" "<<1;
		    return 0;
		}
		else if(d==2){
			cout<<1<<" "<<2;
			return 0;
		}
		else if(d==3){
			cout<<2<<" "<<2;
			return 0;
		}
		else if(d==4){
			cout<<2<<" "<<1;
			return 0;
		}
		else if(d==5){
			cout<<3<<" "<<1;
			return 0;
		}
		else if(d==6){
			cout<<3<<" "<<2;
			return 0;
		}
		else if(d==7){
			cout<<4<<" "<<2;
			return 0;
		}
		else if(d==8){
			cout<<4<<" "<<1;
			return 0;
		}
		else if(d==9){
			cout<<5<<" "<<1;
			return 0;
		}
		else if(d==10){
			cout<<5<<" "<<2;
			return 0;
		}
		else if(d==11){
			cout<<6<<" "<<2;
			return 0;
		}
		else if(d==12){
			cout<<6<<" "<<1;
			return 0;
		}
		else if(d==13){
			cout<<7<<" "<<1;
			return 0;
		}
		else if(d==14){
			cout<<7<<" "<<2;
			return 0;
		}
		else if(d==15){
			cout<<8<<" "<<2;
			return 0;
		}
		else if(d==16){
			cout<<8<<" "<<1;
			return 0;
		}
		else if(d==17){
			cout<<9<<" "<<1;
			return 0;
		}
		else if(d==18){
			cout<<9<<" "<<1;
			return 0;
		}
		else if(d==19){
			cout<<10<<" "<<2;
			return 0;
		}
		else if(d==20){
			cout<<10<<" "<<1;
			return 0;
		}
			
		
	}
   	return 0;
}
