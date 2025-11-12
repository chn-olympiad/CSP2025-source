#include<bits/stdc++.h>
using namespace std;
int x[100][100];
int y[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c,k=1;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>y[i];
	}
	c=y[0];
	for(int j=0;j<=b;j++){
		int d=0;
		if (y[j+1]>=y[j] and j+1<=b){
            d=y[j];
          	y[j]=y[j+1];
         	y[j+1]=d;
        }
	}
	for(int i=0;i<=a*b;i++){
		if (y[i]==c){
			c=i+1;
		}
	}
	for(int i=0;i<a;){
		for(int j=0;j<b;){
			if(j+1<=a and x[j+1][i]==0){
				x[j][i]=k;
				j++;
				i++;
				if(c==k){
					if (i+1>a){
						cout<<j<<' '<<i+1-a;
					}
					else{
						cout<<j<<' '<<i+1;
					}
				}
			}
			else if(j-1<=0 and x[j-1][i]==0){
				x[j][i]=k;
				j--;
				if(c==k){
					if (i+1>a){
						cout<<j<<' '<<i+1-a;
					}
					else{
						cout<<j<<' '<<i+1;
					}
				}
			}
			else if(i+1<=b and x[j][i+1]==0){
				x[j][i]=k;
				i++;
				if(c==k){
					cout<<j<<' '<<i;
				}
			}
			k++;
		}
	}
    return 0;
}

