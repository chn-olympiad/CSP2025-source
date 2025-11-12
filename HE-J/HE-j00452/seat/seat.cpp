#include<bits/stdc++.h>
using namespace std;
long long fe[110],r[2];
bool pa(long long x,long long y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    long long n,m,j,p;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
    	cin>>fe[i];
    	r[1]=fe[1];
	}
	 sort(fe+1,fe+n*m+1,pa);
	   for(long long i=1;i<=n*m;i++){
        if(fe[i]==r[1]){
          j=i;
      	  break;
	    }
	   }
	   cout<<ceil(j*1.0/m)<<" ";
	   p=ceil(j*1.0/n);
	   if(j%2==0&&j>2) cout<<"1";
	   else if(p%2==0) cout<<(n-j%n)+1;
	   else if(j%n==0) cout<<n;
	   else cout<<j%n;
	fclose(stdin);
	fclose(stdout);
return 0;
} 
