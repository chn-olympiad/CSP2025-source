#include<bits/stdc++.h>
using namespace std;
int n,m[1000],sum;
struct node{
	int hg,id;
}a[100000],b[10000],c[10000],aa[50],bb[50],cc[50];
int maxn1=INT_MIN,maxn2=INT_MIN,maxn3=INT_MIN;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>m[i];
	sum=0;
	for(int j=1;j<=m[i];j++){
		cin>>a[j].hg>>b[j].hg>>c[j].hg;
		a[j].id=1;
		b[j].id=2;
		c[j].id=3;
		if(a[j].id==0){
			a[j].hg=0;
		}
		if(b[j].id==0){
			b[j].hg=0;
		}
		if(c[j].id==0){
			c[j].hg=0;
		}
		if(a[j].hg>b[j].hg&&a[j].hg>c[j].hg&&a[j].id){
			sum+=a[j].hg;
			a[j].id=0;
		}
		else if(b[j].hg>a[j].hg&&b[j].hg>c[j].hg&&b[j].id){
			sum+=b[j].hg;
			b[j].id=0;
		}
		else if(c[j].hg>b[j].hg&&c[j].hg>a[j].hg&&c[j].id){
			sum+=c[j].hg;
			c[j].id=0;
		}
		
	}
		cout<<sum<<endl;
}

	
	return 0;
} 
