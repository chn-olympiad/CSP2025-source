#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct node{
	long long x,y,num;
	
};
bool cmp(node a,node b){
	return a.x<b.x;
		
}
bool cmp1(node a,node b){
	return a.num<b.num;
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,ans=0,l;
	long long m[50050];
	cin>>t;
	long long a[50050],b[50050],c[50050];
	while(t!=0){
		long long n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}	
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);

		long long p=n;
		for(int i=n/2;i<n;i++){
			m[p--]=a[i];
			m[p--]=b[i];
			m[p--]=c[i];
		}
		sort(m,m+n);
		for(int i=n-1;i>=0;i--) ans+=m[i];
		cout<<ans<<endl;
		ans=0;
		t--;
	
	}
	return 0;
}
