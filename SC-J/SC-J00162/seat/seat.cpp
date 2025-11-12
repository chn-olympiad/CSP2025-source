#include<bits/stdc++.h>
using namespace std;
int x[105],fir;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a*b;i++){
		cin>>x[i];
	}
	fir=x[0];
	sort(x,x+a*b);
	int cnt=0,flag;
	flag=1;
	if(b%2==0){
		flag=1;
	}else{
		flag=-1;
	}
	if(b%2==1){
		for(int i=b-1;i>=0;i--){
			if(flag==1){
				for(int j=0;j<a;j+=flag){
					if(fir==x[cnt]){
						cout<<i+1<<" "<<j+1;
						return 0;
					}
					cnt++;
				}
				flag=-1;
			}else{
				for(int j=a-1;j>=0;j+=flag){
					if(fir==x[cnt]){
						cout<<i+1<<" "<<j+1;
						return 0;
					}
					cnt++;
				}
				flag=1;
			}
			
		}
	}else{
		for(int i=b-1;i>=0;i--){
			if(flag==1){
				for(int j=0;j<a;j+=flag){
					if(fir==x[cnt]){
						cout<<i+1<<" "<<j+1;
						return 0;
					}
					cnt++;
				}
				flag=-1;
			}else{
				for(int j=a-1;j>=0;j+=flag){
					if(fir==x[cnt]){
						cout<<i+1<<" "<<j+1;
						return 0;
					}
					cnt++;
				}
				flag=1;
			}
			
		}
	}
	
	return 0;
}