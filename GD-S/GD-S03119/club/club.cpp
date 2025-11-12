#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int n,t;
int sum;
int s[6];

int zd(int a,int b,int c){
	if(a>b&&a>c)return a;
	if(b>a&&b>c)return b;
	if(c>b&&c>a)return c;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>t;
	
	for(int i1=1;i1<=t;i1++){ //×éÊý 
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			sum += zd(a,b,c);
		} 
		s[i1]=sum;
		sum=0;
	}
	for(int i1=1;i1<=t;i1++){
		cout<<s[i1]<<endl;
	}
	
	return 0;
}
