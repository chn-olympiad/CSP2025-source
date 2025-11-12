#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],b[1000],u[1000],p[1000],num;
bool c[1000];
void f(int x){
	int k=0;
	if(x==n){
		int r=0;
		for(int i=0;i<n;i++){
			if(p[i]==0){
				r++;
			}
			else if(r<u[b[i]]){
				k++;
			}
			else r++;
		}
		if(k>=m)num++;
		return ;
	}
	for(int i=0;i<n;i++){
		if(c[i]==0){
			b[x]=a[i];
			c[i]=1;
			f(x+1);
			c[i]=0;
		}
	}
}
int main(){
	stdin(employ.in,'w',stdin);
	stdout(employ.out,'r',stdout);
	cin>>n>>m;
	string t;
	cin>>t;
	for(int i=0;i<n;i++)a[i]=i;
	for(int i=0;i<n;i++)cin>>u[i];
	for(int i=0;i<n;i++){
		p[i]=t[i]-'0';
	}
	f(0);
	cout<<num;
	return 0;
}

