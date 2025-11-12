#include<bits/stdc++.h>
using namespace std;
int main(){
	long long c=0,n,t;
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	cin>>t;
	for(int p=1;p<=t;p++){
		long long a[3][100005],f1[100005],f2[100005],f3[100005],l[3][100005];
		cin>>n;
		if(n==2){
			for(int i=1;i<=n;i++){
			    cin>>a[1][i]>>a[2][i]>>a[3][i];
		    }
		    long long c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;
		    c=0;
		    c1=a[1][1]+a[2][2];
			c2=a[1][1]+a[2][2];
			c3=a[2][1]+a[1][2];
			c4=a[2][1]+a[3][2];
			c5=a[3][1]+a[1][2];
			c6=a[3][1]+a[2][2];	
			if(c1>=c){
		    	c=c1;
			}if(c2>=c){
		    	c=c1;
			}if(c3>=c){
		    	c=c1;
			}if(c4>=c){
		    	c=c1;
			}if(c5>=c){
		    	c=c1;
			}
		    if(c6>=c){
		    	c=c1;
			}
		}
		else{
			for(int i=1;i<=n;i++){
			    cin>>a[1][i]>>a[2][i]>>a[3][i];
		    }
		    for(int i=1;i<=n;i++){
		    	c=c+a1[i]+a2[i]-a3[i];
			}
		    
		}
		cout<<c<<endl;
	}
	return 0;
}
