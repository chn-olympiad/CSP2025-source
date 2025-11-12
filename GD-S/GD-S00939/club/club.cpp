#include<bits/stdc++.h>
using namespace std;
int a[100005]={};
int b[100005]={};
int c[100005]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	int n=0;
	int j=0;
	int ans=0;
	int z2=0,z3=0;
	int m1=-1,m2=-1;
	int p1=-1,p2=-1;
	cin>>t;
	for(int p=0;p<t;p++){
		cin>>n;
		ans=0;
		for(int i =1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			z2+=b[i];
			z3+=c[i];
		}
		if(z2==0){
			sort(a,a+100005);
			for(int i =100004;i>100004-n/2;i--){
				ans+=a[i];
			}
			cout<<ans<<endl;
			z2=0;
			z3=0;
		}
		else if(z2!=0&&z3==0){
			for(int i =1;i<=n;i++){
				if(a[i]>m1){
					m1 = a[i];
					p1= i;
				}
				else if(a[i]==m1&&b[i]<b[p1]){
					m1= a[i];
					p1= i;
				}
				if(b[i]>m2){
					m2 = b[i];
					p2= i;
				}
				else if(b[i]==m2&&a[i]<a[p2]){
					m2= b[i];
					p2= i;
				}
				ans += m1+m2;
				a[p1]=0;
				b[p1]=0;
				b[p2]=0;
				a[p2]=0;
				p1=-1;
				p2=-1;
				m1=-1;
				m2=-1;
			}
			cout<<ans<<endl;
		}
	}
	return 0; 
	
} 
