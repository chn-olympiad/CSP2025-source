#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int c=a[1];
    for (int i=1;i<=n*m;i++){
	    for (int j=i+1;j<=n*m;j++){
		    if (a[i]<a[j]){
				int g=a[i];
				a[i]=a[j];
				a[j]=g;
			}		
		}		
	}	
    for (int i=1;i<=n*m;i++){
        if (a[i]==c){
            c=i;
            break;
        }
    }
    int e=c/n;//lie
    int f=c%n;
	if (e%2==1 &&f!=0){//ji
		cout<<e+1<<" "<<n+1-f;	
    }		
	else if (e%2==1 && f==0){
		cout<<e<<" "<<n;	
	}	
	else if (e%2==0 &&f!=0){
		cout<<e+1<<" "<<f;	
	}	
	else if (e%2==0 &&f==0){
		cout<<e<<" "<<1;	
    }	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
