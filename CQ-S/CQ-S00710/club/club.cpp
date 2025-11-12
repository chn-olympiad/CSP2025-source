#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005],t,maxn=0,s1,s2,s3,s4;
int s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j){
						continue;
					}
					if(i==1){
						s1=a[1];
					}else if(i==2){
						s1=b[1]; 
					}else{
						s1=c[1];
					}
					if(j==1){
						s2=a[2];
					}else if(i==2){
						s2=b[2]; 
					}else{
						s2=c[2];
					}
					s=max(s,s1+s2);
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
} 
