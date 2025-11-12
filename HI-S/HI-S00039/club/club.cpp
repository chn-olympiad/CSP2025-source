#include<bits/stdc++.h>
using namespace std;
int n,a1[1005],a2[1005],a3[1005],t,b1,b2,b3,s1,s2,s3,s[105],sum;
int main(){
	//freopen("club.in","r",);
	//freopen("club.out","w",out);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		s[i]=n;
		for(int j=1;j<=n;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
			if(a1[j]>a2[j]&&a1[j]>a3[j]){
				b1++;
			}
			if(a2[j]>a1[j]&&a2[j]>a3[j]){
				b2++;
			}
			if(a3[j]>a2[j]&&a3[j]>a1[j]){
				b3++;
			}
		}
	}
	for(int i=1;i<=t;i++){
		s1=s2=s3=0;
		for(int j=1;j<=s[i];j++){
			if(b1<=s[i]/2){
				s1+=a1[j];
				continue;
			}
			else	if(b2<=s[i]/2){
				s2+=a2[j];
				continue;
			}
			else	if(b3<=s[i]/2){
				s3+=a3[j];
				continue;
			}
		}
		sum=s1+s2+s3;
		cout<<sum<<endl;
	}
	return 0;
} 
