#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a1[N],a2[N],a3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	int ans[10];
	int A1=0,A2=0,A3=0,b2=0,b3=0,c1=0,c3=0,d1=0,d2=0;
	cin>>t;
	for(int j=1;j<=t;j++){
		ans[j]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
		    cin>>a1[i]>>a2[i]>>a3[i];
	        if(n==2){
	        	if(i==1){
	        		A1=a1[i];
	        	    A2=a2[i];
	        	    A3=a3[i];
				}
				if(i==2){
	        	    b2=A1+a2[i];
	        	    b3=A1+a3[i];
	        	    c1=A2+a1[i];
	        	    c3=A2+a3[i];
	        	    d1=A3+a1[i];
	        	    d2=A3+a2[i];
					if(b2>=b3 and b2>=c1 and b2>=c3 and b2>=d1 and b2>=d2){
	        	    	ans[j]=b2;
					}
					if(b3>=b2 and b3>=c1 and b3>=c3 and b3>=d1 and b3>=d2){
	        	    	ans[j]=b3;
					}
					if(c1>=b2 and c1>=b3 and c1>=c3 and c1>=d1 and c1>=d2){
	        	    	ans[j]=c1;
					}
					if(c3>=b2 and c3>=b3 and c3>=c1 and c3>=d1 and c3>=d2){
	        	    	ans[j]=c3;
					}
					if(d1>=b2 and d1>=b3 and d1>=c3 and d1>=c1 and d1>=d2){
	        	    	ans[j]=d1;
					}
					if(d2>=b2 and d2>=b3 and d2>=c3 and d2>=c1 and d2>=d1){
	        	    	ans[j]=d2;
					}
				}
	        }
	    }
	}
	for(int j=1;j<=t;j++){
		cout<<ans[j]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}