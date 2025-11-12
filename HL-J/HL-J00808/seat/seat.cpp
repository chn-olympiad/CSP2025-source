#include<bits/stdc++.h>
using namespace std;
int m,k,n,t,a1,n1,m1;
int b[100001];
bool mn=false;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
    k=n*m;
    for(int i=0;i<k;i++){
    	cin>>b[i];
    	if(i==0){
    		a1=b[i];
		}
    	for(int j=0;j<i;j++){
    		if(b[i]>=b[j]){
    			t=b[j];
    			b[j]=b[i];
    			b[i+1]=t;
    			for(int l=i;l>j;l--){
    				b[l]=b[l-1];
				}
				b[j+1]=b[i+1];
				break;
			}
		}
	}
	for(int i=1;i<=k;i++){
		t=i+1;
    	if(a1==b[i]){
    		if(t%n!=0){
    		    n1=t/n+1;
				m1=t%n+1;
				cout<<m1<<" "<<n1;
			}else{
				n1=n;
    			m1=t/n;
    			cout<<m1<<" "<<n1;
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
} 
