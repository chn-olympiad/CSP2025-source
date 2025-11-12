#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,c; 
long long ans;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int qwe=0;qwe<t;qwe++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a,b,&c);
			if(a>b&&a>c){
				ans+=a;
			}else if(b>a&&b>c){
				ans+=b;
			}else{
				ans+=c;
			}
		}
		cout<<c<<endl;
	}
	
	return 0;
} 
