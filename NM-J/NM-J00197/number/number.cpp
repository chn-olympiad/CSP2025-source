#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[1000001];
    int b[1005],n=0;
    cin>>a;
    for(int i=0;i<=strlen(a);i++){
    	if(a[i]>=48&&a[i]<58){
    		b[n]=a[i]-48;
    		
    		n++;
    		
		}
    	
		
		}
	
	
	sort(b,b+n);
	for(int i=n-1;i>=0;i--){
		cout<<b[i];
	}
    return 0;
}
