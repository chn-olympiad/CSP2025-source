#include<bits/stdc++.h>
using namespace std;
struct y{
	int w;
	int d;
	};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int z1;
	cin>>z1;
	for(int z=0;z<z1;z++){
		int ch=0,n1=0,n2=0,n3=0,nc=0;
		y a1[10001],a2[10001],a3[10001],ma[10001];
		int n,ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a1[i].d,&a2[i].d,&a3[i].d);
			if(a1[i].d>a2[i].d&&a1[i].d>a3[i].d){ma[i].d=a1[i].d;ma[i].w=1;n1++;}
			else if(a2[i].d>a1[i].d&&a2[i].d>a3[i].d){ma[i].d=a2[i].d;ma[i].w=2;n2++;}
			else if(a3[i].d>a1[i].d&&a3[i].d>a2[i].d){ma[i].d=a3[i].d;ma[i].w=3;n3++;}
			else if(a1[i].d==a2[i].d){ma[i].d=a1[i].d;ma[i].w=1;
				nc++;
				}
			a1[i].w=a2[i].w=a3[i].w=i;
			}
		if(n==2){
			for(int i=0;i<n;i++){
				ans+=ma[i].d;
			}
			cout<<ans<<endl;
			continue;
			}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a1[i].d<a1[j].d){
					ch=a1[i].d;
					a1[i].d=a1[j].d;
					a1[j].d=ch;
					ch=a1[i].w;
					a1[i].w=a1[j].w;
					a1[j].w=ch;
				}
				}
			}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a2[i].d<a2[j].d){
					ch=a2[i].d;
					a2[i].d=a2[j].d;
					a2[j].d=ch;
					ch=a2[i].w;
					a2[i].w=a2[j].w;
					a2[j].w=ch;
				}
				}
			}
		for(int i=0;i<nc;i++){
			if(n1<n2){
				n1++;
				}
			else{
				n2++;}
			}
	//	cout<<n1<<" "<<n2<<endl;
		if(n1>n/2){
			n1=n/2;
			for(int i=0;i<n1;i++){
				if(a1[i].d==ma[a1[i].w].d){
					ans=ans+a1[i].d;
					}
				else {
					ans=ans+ma[a1[i].w].d;
					n1++;
					}
				ma[a1[i].w].w=-1;
				}
				for(int i=0;i<n;i++){
					if(ma[i].w!=-1){
						ans+=a2[i].d;
	//					cout<<ma[i].d;
				}
		}
			
			}
		else if(n1==n2){
			
			for(int i=0;i<n;i++){
				ans+=ma[i].d;
		}
			}
		else {
			n2=n/2;
			for(int i=0;i<n2;i++){
				if(a2[i].d==ma[a2[i].w].d){
					ans=ans+a2[i].d;
	//				cout<<ma[a2[i].w].d;
					}
				else {
					ans=ans+a1[i].d;
					n2++;
					}
				ma[a2[i].w].w=-1;
				}
				for(int i=0;i<n;i++){
					if(ma[i].w!=-1){
						ans+=a1[i].d;
	//					cout<<ma[i].d;
				}
		}
			}
		
		cout<<ans<<endl;
	}
	return 0;
}
