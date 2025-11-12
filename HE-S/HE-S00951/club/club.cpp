#include<bits/stdc++.h>
using namespace std;
int a[10086],b[10086],c[10086];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,A=0,B=0,C=0;
	cin>>t;
	int q[t];
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			
		}
		for(int j=1;j<=n;j++){
			if(a[j]>b[j]&&a[j]>c[j]&&A<n/2){
				A++;
				q[i]+=a[j];
			}  
			if(b[j]>a[j]&&b[j]>c[j]&&B<n/2){
				B++;
				q[i]+=b[j];
			}
			if(c[j]>b[j]&&c[j]>a[j]&&C<n/2){
				C++;
				q[i]+=c[j];
			}
		}
	
	}
	for(int i=1;i<=t;i++){
		cout<<q[i]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
