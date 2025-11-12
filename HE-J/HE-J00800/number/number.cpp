#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    for (int i=1;i<=1000005;i++){
	    cin >> s;
   }
   int a,b,c;
   len=lenstrong.s;
   for (int i=1;i<=len;i++){
   	    if (i>="0" && i<="9"){
   	    	a=i;
   	    	if (i+1>="0" && i+1<="9"){
   	    		a=a*10+i;
   	    		b=i*10+a;
   	    		if (a>=b){
   	    			c=a;
				   }else{
				   	c=b;
				   }
			   }
		}
   }
   cout << a;
	return 0;
	//±£´æÊ± ½â×¢ÊÍ 
}
