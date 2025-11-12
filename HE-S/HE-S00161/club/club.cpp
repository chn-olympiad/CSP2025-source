#include<bits/stdc++.h>
using namespace std;
	int t;
	int n;
	int a,b,c;
	int g;
	int zong = 0;

int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	
	
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		for(int j = 0; j <= n; j++){
			cin >> a >> b >> c;
	  if(a < b && c < b){
				g = b;
	  }else if(a <= c && c <= b){
	  			g = b;
	  }else if(b <= a && a <= c){
	  			g = c;
	  }else if(b <= c && c <= a){
	  			g = a;
	  }else if(c <= a && a <= b){
	  			g = b;	
	  }else if(c <= b && b <= a){
	  			g = a;			  		
	  }	
		
			zong = zong+g;
		
				
	}		
cout << zong;
	
}


return 0;
};
