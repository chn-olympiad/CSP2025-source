#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int n1=0,m1=0;
    int a[100];
    cin>>n>>m;
    int max=0;
    int p=0;
    for(int i=0;i<n*m;i++){
    	cin>>a[i];
	}
	
    int a1=a[0];
    for(int i=0;i<n*m;i++){
    	int t;
    	for(int j=0;j<n*m;j++){
    		if(max<a[j]){
    			max=a[j];
    			t=j;
			}
		}
    	a[t]=0;
		p+=1;
		
		if(max==a1){ 
			p--;
			break; 
		}
		max=0;
	}
	while(p>0){//
		if(m1%2==0){
			if(n1+1>=n){
				m1+=1;
			}
			else{ 
				n1+=1;
			}
		}
		else{
			if(n1-1<0){
				m1+=1;
			}
			else{
				n1-=1;
			}
		}
		p--;
	}
	
	cout<<m1+1<<" "<<n1+1;
    return 0;
}