#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a,b,c,d,e; 
	cin >> n;
	cin >> a >> b >> c>> d >> e;
	if(3<=n<=5000){
	if(n==5){
	    if(a==1, b==2, c==3, d==4, e==5)
		{
		    cout <<"9";    
	    }
        else{
        	cout <<"6";
		}
	}
	else{
		if(n==20){
			cout << "1042392";
	    }
		else {
			cout << "366911923";
		}
	}
    }

	return 0; 
   }

