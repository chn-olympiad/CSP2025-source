#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>t;
	int a=0,b=0,c=0;
	int cnt=0;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int x1=0,x2=0,x3=0;
			cin>>x1>>x2>>x3;
			if(x1 >x2 && x1>x3){
				a++;
				if(a<=n/2){
					cnt+=x1; 		
				}else{
					if(x2>=x3 && b<=n/2){
						b++;
						cnt+=x2;
					}else {
						c++;
						cnt+=x3;
					}
				}
			}else if(x2>x1 && x2>x3){
				b++;
				if(b<=n/2){
					cnt+=x2; 		
				}else{
					if(x1>=x3 && a<=n/2){
						a++;
						cnt+=x1;
					}else {
						c++;
						cnt+=x3;
					}
				}
			}else if(x3>x1 && x3>x2){
				c++;
				if(c<=n/2){
					cnt+=x3;		
				}else{
					if(x1>=x2 && a<=n/2){
						a++;
						cnt+=x1;
					}else {
						c++;
						cnt+=x2;
					}
			}
		}
		}
		cout<<cnt; 
		a=0,b=0,c=0,cnt=0;
	}
	
	
	
	return 0;
}
