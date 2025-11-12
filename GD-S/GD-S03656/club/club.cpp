#include <bits/stdc++.h>
using namespace std;
int a1[100001],a2[100001],a3[100001],s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int b1=0,b2=0,b3=0;
		s=0;
		for(int j=1;j<=n;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
		}
		for(int k=1;k<=n;k++){
			if(a1[k]>a2[k] && a2[k]>a3[k]){
				 
				if(b1<n/2){
					s+=a1[k];
					b1++;
				}
				else if(b2<n/2){
					s+=a2[k];
					b2++;
				}
			}
			else if(a2[k]>a1[k] && a1[k]>a3[k]){
				
				if(b2<n/2){
					s+=a2[k];
					b2++;
				}
			}
			else if(a2[k]>a3[k] && a3[k]>a1[k]){
				
				if(b2<n/2){
					s+=a2[k];
					b2++;
				}
			}
			else if(a1[k]>a3[k] && a3[k]>a2[k]){
				
				if(b1<n/2){
					s+=a1[k];
					b1++;
				}
			}
			else if(a3[k]>a2[k] && a2[k]>a1[k]){
				
				if(b3<n/2){
					s+=a3[k];
					b3++;
				}
			}
			else if(a3[k]>a1[k] && a1[k]>a2[k]){
				
				if(b3<n/2){
					s+=a3[k];
					b3++;
				}
			}
		}
		cout<<s<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
