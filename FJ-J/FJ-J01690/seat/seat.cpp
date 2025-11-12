#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	
	long long a,b;
	int vss[1000005];
	cin>>a>>b;
	int akm=0;
	int wei=0;
	for(long long i=1;i<=a*b;i++){
		cin>>vss[i];
	}
	akm=vss[1];
	
	sort(vss+1,vss+a*b+1);
	for(int i=a*b;i>=1;i--){
		if(vss[i]==akm){
			wei=a*b-i+1;
			break;
		}
	}
	int ak=wei/a;
	
	int ax=wei%a;
	
	if(ax==0){
	    if(ak%2==0){
	    	cout<<ak<<' '<<1;
		}else{
			cout<<ak<<' '<<a;
		}
    }
	else {
		if((ak+1)%2==0) cout<<ak+1<<' '<<a-ax+1;
		else cout<<ak+1<<' '<<ax;
	}
	return 0;
	
	fclose(stdin);
	fclose(stdout);
} 
