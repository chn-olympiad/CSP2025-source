#include<bits/stdc++.h>
using namespace std;
int n,i,a[1000000],d[3],t,s,ma,r,k,j;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(j=1;j<=n;j++){
			cin>>a[j];
			k=0;
			ma=0;
			for(int y=1;y<=3;y++)
				d[y]=0;
			for(int p=1;p<=n;p++){
				if(a[p]>ma){
					k=p;
					ma=a[k];
				}
			}
			s+=a[j];
			cout<<s<<endl;
		}
	}
	return 0;
}
