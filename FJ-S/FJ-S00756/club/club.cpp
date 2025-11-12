#include <bits/stdc++.h>
using namespace std;
long long a1,a2,a3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	long long t;
	long long w=0;
	cin>>t;
	for(long long i=0;i<t;i++){
		long long n,q=0;
		long long x1=0,x2=0,x3=0;
		cin>>n;
		for(long long j=0;j<n;j++){
			cin>>a1>>a2>>a3;
			if(max(a1,max(a2,a3))==a1){
				x1++;
				q+=a1;
			}else if(max(a1,max(a2,a3))==a2){
				x2++;
				q+=a2;
			}else{
				x3++;
				q+=a3;
			}
		}
		if(max(x1,max(x2,x3))<=n/2){
			cout<<q<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
