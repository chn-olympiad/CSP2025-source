#include<bits/stdc++.h>
using namespace std;
int t,n,a1,a2,a3,p1=0,p2=0,p3=0;
int main(){
	int max[11451];
	int d=1;
	int w[11451];
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin>>t;
	for(int s=1;s<=t;++s){
		cin>>n;
		for(int j=1;j<=n;++j){
			cin>>a1>>a2>>a3;
			if(a1>=a2){
				w[j]=a1;
				p1+=1;
				if(p1>(n/2)&&a2>=a3){
					w[j]=a2;
					p1=p1-1;
				}
				if(p1>(n/2)&&a2<a3){
					w[j]=a3;
					p1=p1-1;
				}
			}
			else{
				w[j]=a2;
				p2+=1;
				if(p2>(n/2)){
					w[j]=a3;
					p2=p2-1;
				}
			}
			if(w[j]<=a3){
				w[j]=a3;
				p1=p1-1;
				p3+=1;
				if(p3>(n/2)){
					w[j]=a1;
				}
			}			
			max[d]+=w[j];						
		}
		d+=1;
	}
	for(int e=1;e<d;++e){
		cout<<max[e]<<endl;
	}
	return 0;
}
