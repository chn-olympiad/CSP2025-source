#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001],c[100001];
int n,t,k;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int h=1;h<=t;h++){
		k=0; 
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        sort(a+1,a+n+1);
        for(int i=n;i>n/2;i++) k=k+a[i];
        cout<<k<<endl;
    }
}
