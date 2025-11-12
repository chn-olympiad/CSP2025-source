#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[105];
struct se{
    int h;
    int l;
    }s[105];
bool cmp(int a,int b){
    return a>b;
    }
int main(){
    
    freeopen("seat.in","r",stdin);
    freeopen("seat,out","w",stdout);
    
    cin>>n>>m;
   
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int b=a[1];
    int p;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
    	
        if(a[i]==b){
            p=i;

        }

    }
    int l;
    if(p%n==0){
    	l=p/n;
	}
	else{
		l=p/n+1;
	}
    int h;
    if(l%2==1){
    	if(p%n==0){
    		h=n;
		}
		else{
			h=p%n;
		}
        
    }
    else{
        h=n-p%n+1;
    }
    cout<<l<<" "<<h;
    return 0;

}

