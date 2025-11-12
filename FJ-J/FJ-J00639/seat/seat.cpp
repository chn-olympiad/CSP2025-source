#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],asuo,q,p;
string s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
			if(i==1)asuo=a[i];
		}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==asuo){
			
			q=(n*m-i+1)/m;
			p=(n*m-i+1)%m;
			if(p!=0)q++;
			 
			if(q%2==0){
				if(p==0){
					p=1;
				}else{
					p=m-p+1;
				}
					
			}else{
				if(p==0){
					p=m;
			}	
		}
		break;
	}		
	}
	cout<<q<<" "<<p;
	}
	

