#include<bits/stdc++.h>
using namespace std;
long long t;
struct Eudg{
	long long c1,c2,c3,dui;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	long long n[t];
	for(int h=0;h<t;h++){
		cin>>n[h];
		long long mid=n[h]/2;
		Eudg a[100000];
		for(int i=0;i<n[h];i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		}
		if(n[h]==2){
			long long t1=a[0].c1+a[1].c2,t2=a[0].c1+a[1].c3,t3=a[0].c2+a[1].c1,t4=a[0].c2+a[1].c3,t5=a[0].c3+a[1].c1,t6=a[0].c3+a[1].c2;
			long long x1=max(t1,t2);
			long long x2=max(t3,x1);
			long long x3=max(t4,x2);
			long long x4=max(t5,x3);
			long long x5=max(t6,x4);
			cout<<x5<<endl;
		}
		else{
			long long m[100000];
			for(int i=0;i<n[h];i++){
				long long temp=max(a[i].c1,a[i].c2);
				m[i]=max(a[i].c3,temp);
				if(m[i]==a[i].c1){
					a[i].dui=1; 
				}
				if(m[i]==a[i].c2){
					a[i].dui=2; 
				}
				if(m[i]==a[i].c3){
					a[i].dui=3; 
				}
			}
			vector<long long>c11(100000) ;
			vector<long long>c22(100000) ;
			vector<long long>c33(100000) ;
			long long k1=0,k2=0,k3=0;
			for(int i=0;i<n[h];i++){
				if(a[i].dui==1){
					if(k1==mid){
						for(int j=0;j<mid;j++){
							if(m[i]>c11[j]){
								c11[j]=m[i];
								break;
							}
						}
					}
					else{
						c11[k1]=m[i];
						k1++;
					}
				}
				if(a[i].dui==2){
					if(k2==mid){
						for(int j=0;j<mid;j++){
							if(m[i]>c22[j]){
								c22[j]=m[i];
								break;
							}
						}
					}
					else{
						c22[k2]=m[i];
						k2++;
					}
				}
				if(a[i].dui==3){
					if(k3==mid){
						for(int j=0;j<mid;j++){
							if(m[i]>c33[j]){
								c33[j]=m[i];
								break;
							}
						}
					}
					else{
						c33[k3]=m[i];
						k3++;
					}
				}
			}
			long long ans=0;
			for(int i=0;i<k1;i++){
				ans+=c11[i];
			}
			for(int i=0;i<k2;i++){
				ans+=c22[i];
			}	
			for(int i=0;i<k3;i++){
				ans+=c33[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
