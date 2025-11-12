#include <bits/stdc++.h>
using namespace std;
int a[20],m;
char c[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>c;
    for(int i=0;i<1000000;i++){
    	if((c[i]-'0')<=9&&(c[i]-'0')>=0){
    		int x=c[i]-'0';
    		a[x]++;
    	}
    }
    for(int i=9;i>=0;i--){
        if(a[i]>=1){
		    for(int j=1;j<=a[i];j++){
		        printf("%d",i);	
		    }
		}
    }
    return 0;
}  
