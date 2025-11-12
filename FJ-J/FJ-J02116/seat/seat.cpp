 #include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int j,k,t;
int u;
int main(){
	cin>>n>>m;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
		if(n==1&&m==1){
		cout<<1<<' '<<1<<endl;
		return 0;
	}
    	sort(a+1,a+n*m+1);
 	a[1]=t;
	for(int i=1;i<=n*m;i++){
		if(t==a[i]){
			 u=i;
		}
	} 
	if(u<=m){
		cout<<1<<' '<<u;
		return 0;
	}else if(n==2){
		if(u<=2*m){
			cout<<2<<' '<<u;
			return 0;
		}
	}else if(n==3){
		if(u<=3*m){
			cout<<3<<' '<<u;
			return 0;
		}else if(n==4){
		if(u<=4*m){
			cout<<4<<' '<<u;
			return 0;
		}
	}
}
	else if(n==4){
		if(u<=4*m){
			cout<<4<<' '<<u;
			return 0;
		}
	}
	else if(n==5){
		if(u<=5*m){
			cout<<5<<' '<<u;
			return 0;
		}
	}
	else if(n==6){
		if(u<=6*m){
			cout<<6<<' '<<u;
			return 0;
		}
	}
	else if(n==7){
		if(u<=7*m){
			cout<<7<<' '<<u;
			return 0;
		}
	}
	else if(n==8){
		if(u<=8*m){
			cout<<8<<' '<<u;
			return 0;
		}
	}
	else if(n==9){
		if(u<=9*m){
			cout<<9<<' '<<u;
			return 0;
		}
	}
	else if(n==10){
		if(u<=10*m){
			cout<<10<<' '<<u;
			return 0;
		}
	}	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
    if(u==n*m){
    	cout<<1<<' '<<1;
    	return 0;
	}

		if(n==1&&m==2){
			if(a[1]==1){
			
		cout<<1<<' '<<2<<endl;
		return 0;
	}else{
	cout<<1<<' '<<1<<endl;
	return 0;	
	} 
	}
		if(n==2&&m==1){
			if(a[1]==1){
			
		cout<<2<<' '<<1<<endl;
		return 0;
	}else{
	cout<<1<<' '<<1<<endl;
	return 0;	
	}
	}
	
	
	return 0;
} 

