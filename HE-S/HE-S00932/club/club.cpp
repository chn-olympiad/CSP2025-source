#include<bits/stdc++.h>
using namespace std;
int MAX(int a,int b,int c){
	int max=0;
	if(a>=max){
		max=a;
	}
	if(b>=max){
		max=b;
	}
	if(c>=max){
		max=c;
    }
    return max;
			
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int q=0; q<t; q++){
		int z;
		cin>>z;
		int a,b,c;
		int a2=0,b2=0,c2=0;
		int ans=0;
		for(int i=0; i<z; i++){
			int m;
			cin>>a>>b>>c;
			m=MAX(a,b,c);
			if(m==a&&a2<==z/2){
			   ans+=a;
			   a2++;
			}else if(m==b&&b2<=z/2){
				ans+=b;
				b2++;
			}else if(m==c&&c2<=z/2){
				ans+=c;
				c2++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
