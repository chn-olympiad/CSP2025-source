//GZ-S00478 贵阳市第三中学 陈致星 
#include <bits/stdc++.h>
using namespace std;
int t,n,m,q,u,o,p; 
long long d[10002];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int a,b,c;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
		}
		for(int j=1;j<=n;j++){	
			if(a>b&&b>c){
				m=a;
				u+=1;
			}
			else if(b>a&&a>c){
				m=b;
				o+=1;
			}
			else if(c>a&&a>b){
				m=c;
				p+=1;
			}
			if(u>n/2){
				if(b>c) q+=b;
				else q+=c;
			}
			else if(o>n/2){
				if(a>c) q+=a;
				else q+=c;
			}
			else if(p>n/2){
				if(b>a) q+=b;
				else q+=a;
			}
			else{
				q+=m;
			}
		}
		d[i]=q;
		q=0;
	}
	for(int i=1;i<=t;i++){
		if(d[i]!=0){
			cout<<d[i]<<"\n";
		}
	}
	return 0;
}
