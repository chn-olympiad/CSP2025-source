#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a,b,c;
		int a1=0,b1=0,c1=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			int sum=max(a,max(b,c));
			if(sum==a){
				if(a1<n/2){
					a1++;
					ans+=a;
				}
				else if(max(b,c)==b){
					b1++;
					ans+=b;
				}
				else{
					c1++;
					ans+=c;
				}
			}
			else if(sum==b){
				if(b1<n/2){
					b1++; 
					ans+=b;
				}
				else if(max(a,c)==a){
					a1++; 
					ans+=a;
				}
				else 
				{
					c1++; 
					ans+=c;
				}
			}
			else if(sum==c){
				if(c1<n/2) {
					c1++;
					ans+=c;
				} 
				else if(max(b,a)==b){
					b1++;
					ans+=b;
				}
				else{
					c1++;
					ans+=c;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
//Ren5Jie4Di4Ling5%
