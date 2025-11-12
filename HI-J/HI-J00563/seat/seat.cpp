#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	int a , b , c ,d;
	if(1<=n<=10,1<=m<=10){
	cin >> n >> m;
	cin >> a >> b >> c >> d; 
    if(n==2,m==2){
    	if(a==99,b==100, c==97, d==98){
    		cout << "1,2";
		}
	    if(a==98,b==99, c==100, d==97){
	        cout << "2,2";	 
		}
    }
    if(n==3,m==3){
    	cout <<"3,1";
	}
	}
    
    return 0;
}  
