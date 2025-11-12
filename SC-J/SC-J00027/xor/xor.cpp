#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l[100000],r[100000],lr[100000];
};
node c;
long long n,s,a[500003],sum=0,zh=1;
bool b[500003];
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long ans=0;
			for(int k=i;k<=j;k++)ans=ans^a[k];
			if(ans==s){
				c.l[zh]=i;
				c.r[zh]=j;
				c.lr[zh]=c.r[zh]-c.l[zh]+1;
				zh++;
			}
		}
	}
	sort(c.lr+1,c.lr+1+zh);
	for(int i=1;i<=zh;i++){
		bool pd=true;
		for(int j=c.l[i];j<=c.r[i];j++)if(b[j]==1)pd=false;
		if(pd==true){
			for(int j=c.l[i];j<=c.r[i];j++)b[j]=1;
			sum++;
		}
	}
	cout<<sum-1;
	return 0;
}