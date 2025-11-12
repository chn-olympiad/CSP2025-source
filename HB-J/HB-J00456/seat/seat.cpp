#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r","in");
	freopen("seat.out","w","out");
	
	int n,m,g,a,na,ma;
	cin>>n>>m>>endl>>g;
	int a=100%g;
	
	if((m-1)*n+1<=a<=m*n){//zong de fan wei
		if(a%n=0){//a wei n de bei shu shi
		    int ma=a/n;
		    }
	    if(a%n!=0){//a bu wei si de bei shu shi
		    int ma=a/n;
		    }
		if(n/a<=1){//1-n de fan wei
			int na=a;
		    }
		if(a/n>ma){//>n qie xiang xia de fan wei
			int na=a%n;
		    }
		if(a/n>ma-1){//(>n)xiang shang de fan wei
			int na=ma*n-a=1;
			}
		}
		
	cout<<n<<m;
	return 0;
}
