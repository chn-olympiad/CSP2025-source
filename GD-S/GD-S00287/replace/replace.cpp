#include<bits/stdc++.h>
using namespace std;
long long n,q,a[100000],b[100000],c[1000000],d[1000000];
string s1,s2,t1,t2;
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int j=1;j<=s1.size();j++){
			c[i]=s1[j];
		}
		for(int j=1;j<=s2.size();j++){
			d[i]=s2[j];
		}
	}
	for(int i=1;i<=q;i++){
		int sum=0;
		cin>>t1>>t2;
		for(int j=1;j<=t1.size();j++){
			a[j]=t1[j];
		}
		for(int j=1;j<=t2.size();j++){
			b[j]=t2[j];
		}
		for(int j=1;j<=t1.size();j++){
			int t=0;
			for(int i=1;i<=n;i++){
				if(a[j]==c[i]&&b[j]==d[i])
				t=1;
			}
			if(t)
				if(a[j]!=b[j]){
					sum++;
				}
		}
		cout<<sum;
	}
}
