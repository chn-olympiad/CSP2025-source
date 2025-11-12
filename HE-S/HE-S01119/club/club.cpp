#include<bits/stdc++.h>
using namespace std;
long long n,t,q=0,w=0,e=0,maxa,maxb,maxc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		cin>>n;
		long long a[1001],b[1001],c[1001];
		for(long long i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		
			if(b[i]>=a[i]&&b[i]>=c[i]){
				a[i]=0;
				c[i]=0;
			}
			if(c[i]>=a[i]&&c[i]>=b[i]){
				b[i]=0;
				a[i]=0;
			}
			if(a[i]>=b[i]&&a[i]>=c[i]){
				b[i]=0;
				c[i]=0;
			}
		}
		for(long long i=0;i<n;i++){
			q+=a[i];
			w+=b[i];
			e+=c[i];
		}
		
			
		
		}
		cout<<q+w+e<< endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;

}
