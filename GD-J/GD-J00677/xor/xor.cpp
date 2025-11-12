#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int a,b,c[1005],maxx=0;
	fropen("xor.in","r",strin);
    fropen("xor.out","w",strout);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
    	cin>>c[i];
    	if(c[i]>=maxx){
    	    maxx=c[i];
		}
	}
	cout<<maxx;
    return 0;
} 
