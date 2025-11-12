#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+2],l=n*m,c[1];
	for(int i=1;i<=l;i++){
        cin>>a[i];
	}
	int cj=a[1];
	for(int i=1;i<=l-1;i++){
        for(int j=i+1;j<=l;j++){
            if(a[i]<a[j]){
                c[0]=a[i];
                a[i]=a[j];
                a[j]=c[0];
            }
        }
	}
	int x=1,y=1,fx=0;
	for(int i=1;i<=l;i++){
        if(a[i]==cj){
            break;
        }
        if(y==m&&fx==0){
            x++;
            fx=1;
        }
        else if(y==1&&fx==1){
            x++;
            fx=0;
        }
        else if(fx==1){
            y--;
        }
        else if(fx==0){
            y++;
        }
	}
	cout<<x<<" "<<y;
	return 0;
}
