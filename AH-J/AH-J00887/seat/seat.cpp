#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n,m;
int a[10050];
int f,x=1,y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int len=n*m;
    bool l=1;
    for(int i=0;i<len;i++){
		cin>>a[i];
		if(i==0)f=a[i];else{
			if(f<a[i]){
				if(l){x++;}else{x--;}
				if(x==n+1){x=n;y++;l=0;}
				if(x==0){x=1;y++;l=1;}
			}
		}
	}
    cout<<y<<" "<<x;
    return 0;
   
}
