#include<bits/stdc++.h>
using namespace std;
int s[10086],c[10086];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	bool r=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
		if(s[i]==0){
			r=1;
		}
	}
	if(m==1&&r==0){
		if(s[1]==1){
		   long long sum=1; 
		   for(long long i=1;i<=n;i++){
			   sum*=i;
		   }
		   cout<<sum;
		}
		else{
			bool r1=0;
			int sum1=0;
			for(int i=1;i<=n;i++){
				if(s[i]==0)
				sum1++;
			}
			for(int i=1;i<=n;i++){
			    if(c[i]<=sum1)
			    r1=1;
			}
			if(r1){
				long long sum=0;
			   for(int i=1;i<=n;i++){
			       sum*=i;
		       }
		    cout<<sum;	
			}
		}
		
	}
	
	return 0;
}
