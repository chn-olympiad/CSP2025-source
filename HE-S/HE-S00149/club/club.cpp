#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n],b[n],c[n];
		
		int an=0,bn=0,cn=0,ma[n],mb[n],mc[n];
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>=b[j]&&a[j]>=c[j]){
				ma[an++]=a[j];
			}
			else if(b[j]>=c[j]){
				mb[bn++]=b[j];
			}
			else{
				mc[cn++]=c[j];
			}
		}
	return 0;
}
