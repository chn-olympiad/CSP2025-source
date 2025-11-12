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
		int nn=n/2;
		int ans=0;
		int club1=0,club2=0,club3=0;
		for(int i=0;i<n;i++){
			int n1,n2,n3;
			cin>>n1>>n2>>n3;
			if(n1>n2&&n1>n3){
				if(club1<nn){club1++;
					ans+=n1;}
				else {
					if(n2>=n3){
						club2++;
						ans+=n2;
						}
					else {club3++;
						ans+=n3;}
					}
				
				}
			else if(n2>n1&&n2>n3){
				if(club2<nn){club2++;
					ans+=n2;}
				else {
					if(n1>=n3){
						club1++;
						ans+=n1;
						}
					else {club3++;
						ans+=n3;}
					}
				}
				else if(n3>n1&&n3>n2){
				if(club3<nn){club3++;
					ans+=n3;}
				else {
					if(n1>=n2){
						club1++;
						ans+=n1;
						}
					else {club2++;
						ans+=n2;}
					}
				}
		}
		cout<<ans<<endl;
		
		
		
		
	}
	return 0;
	}
