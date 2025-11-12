#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int t,n;
int a[1007],b[1007],c[1007];
int A,B,C;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int s=0;
		for(int j=0;j<n;j++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				A++;
				s+=a[i];
			}if(b[i]>=a[i]&&b[i]>=c[i]){
				B++;
				s+=b[i];
			}if(c[i]>=b[i]&&c[i]>=a[i]){
				C++;
				s+=c[i];
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
