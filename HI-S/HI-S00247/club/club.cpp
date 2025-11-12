#include<bits/stdc++.h>
using namespace std;
int n,t,maxn=0;
int a[100005]={},b[100005]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int h=1;h<=t;h++){
		cin>>n;
		if(n==2){
			cin>>a[1]>>a[2]>>a[3]>>b[1]>>b[2]>>b[3];
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j && a[i]+b[j]>maxn){
						maxn=a[i]+b[j];
					}
				}
			}
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
