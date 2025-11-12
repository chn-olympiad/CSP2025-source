#include<bits/stdc++.h>
using namespace std;
long long int a[100000000],b;
long long int at[100000000];
long long int n;
void jiancha(long long int x,long long int m,long long int h,long long int s){
	long long int m1=m;
	if(x==1){
		for(long long int i=s;i<=n;i++){
			if(at[i]==1){
				m1=max(m,a[i]);
				if((h+a[i])>(m1*2)){
					b+=1;
				}
				m1=m;
			}
		}
	}else{
		for(long long int i=s;i<=n;i++){
			if(at[i]==1){
				m1=max(m,a[i]);
				at[i]=0;
				jiancha(x-1,m1,h+a[i],i+1);
				m1=m;
				at[i]=1;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(long long int i=1;i<=n;i++){
		cin>>a[i];
		at[i]=1;
	}
	for(long long int i=3;i<=n;i++){
		jiancha(i,0,0,1);
	}
	cout<<b;
	return 0;
} 
