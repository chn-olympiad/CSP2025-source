#include<bits/stdc++.h>
using namespace std;

int m,n,b,a[10005],sum=0;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>m>>n;
for(int i=1;i<=m*n;i++)
  {
	  cin>>a[i];
	   b=a[1];
  }
if(m==1&&n==1) {cout<<m<<" "<<n;return 0;}
sort(a+1,a+1+n*m);
for(int i=m*n;i>=1;i--)
{
	if(a[i]!=b) sum++;
	       else {sum++;break;
	}
}
	 if(sum<=n) {cout<<1<<" "<<sum;return 0;}
	 if(sum>n){
		        if(sum%n==0) {
					           if((sum/n)%2==0) {cout<<sum/n<<" "<<1;return 0;}
					                       else {cout<<sum/n<<" "<<n;return 0;}
					         }
		        if(((sum/n)+1)%2==0) {cout<<sum/n+1<<" "<<2*n-sum+1;return 0;}
	            if(((sum/n)+1)%2==1) {cout<<sum/n+1<<" "<<sum%n;return 0;}				      
	          }
fclose(stdin);
fclose(stdout);
   return 0;
}
