#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	cin>>t;
	for(int j=1;j<=t;j++){
		long long n,a[100005][4],b[4],a1=0,a2=0,a3=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>b[1]>>b[2]>>b[3];
			if(b[1]>=b[2]&&b[1]>=b[3]){
				if(a1>=n/2){
					if(b[2]>=b[3]){
							a2++;
							sum+=b[2];
					}
					else{
						a3++;
						sum+=b[3];
					}
				}
				else{
					a1++;
					sum+=b[1];
				}
			}
			else if(b[2]>=b[3]){
				if(a2>=n/2){
					a3++;
					sum+=b[3];
				}
				else{
					a2++;
					sum+=b[2];
				}
			}
			else if(b[3]>=b[2]){
				if(a3>n/2){
					a2++;
					sum+=b[2];
				}
				else{
					a3++;
					sum+=b[3];
				}
			}
		}
		cout<<sum<<endl;
	}
}
