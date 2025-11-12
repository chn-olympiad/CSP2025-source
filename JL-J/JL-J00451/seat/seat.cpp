#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,k,h,p;
	cin>>n>>m;
	int j=n*m;
	int a[j];
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
		p=a[1];
		sort(a+1,a+1+j);
		for(int i=1;i<=j;i++){if(a[i]==p)s=j-i+1;
			}
			
				
			if(s%n==0)k=s/n;
			if(s<=m)k=1;
			else k=s/n+1;
			if(k==1){h=s;
				cout<<k<<" "<<h;
				return 0;}
			if(k%2==0&&k!=1){
				if(s%n==0)h=1;
				else
				h=n-((s%n)-1);}
			else h=s%n;
			cout<<k<<" "<<h;
	return 0;
}
