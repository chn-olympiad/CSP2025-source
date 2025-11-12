#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[101];
int c,b,num;
int n=1,m;
cin>>c>>b;
num=c*b;
for(int i=1;i<=num;i++){
cin>>a[i];
	
} 
for(int j=2;j<=num;j++){
		if(a[j]>=a[1]){
		m++;
		num--;
	    }
	    if(a[1]>=a[j]){
			num--;
		}
		
		
		if(v==0){
			cout<<n<<" "<<m;
			}
	}

return 0;
} 
