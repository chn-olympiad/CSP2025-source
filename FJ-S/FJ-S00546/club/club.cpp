#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		int haogandu=0;
		int one=0;
		int two=0;
		int three=0;
		cin>>n;
		int a=n/2;
		int o[a];
		int wo[a];
		int ree[a];
		for(int j=1;j<=n;j++){
			int b,c,d;
			cin>>b>>c>>d;
			if(max(b,max(c,d))==b){
				one+=1;
				if(one<=a){
					o[j]=b;
				}else{
					if(max(c,d)==c){
						two+=1;
						if(two<=a){
							wo[j]=c;
						}else{
							three+=1;
							ree[j]=d;
						}
					}else{
						three+=1;
						if(three<=a){
							ree[j]=d;
						}else{
							two+=1;
							wo[j]=c;
						}
					}
				}
			}if(max(b,max(c,d))==c){
			
				two+=1;
				if(two<=a){
					wo[j]=b;
				}else{
					if(max(b,d)==b){
						one+=1;
						if(one<=a){
							o[j]=b;
						}else{
							three+=1;
									
						
							if(three<=a){
							ree[j]=d;
							}else{
							one+=1;
							o[j]=b;
							}
						}
					}
		}
			}if(max(b,max(c,d))==d){
				three+=1;
				if(three<=a){
					ree[j]=d;
				}else{
					if(max(c,b)==c){
						two+=1;
						if(two<=a){
							wo[j]=c;
						}else{
							one+=1;
				
						if(one<=a){
							o[j]=b;
						}else{
							two+=1;
							wo[j]=c;
						}
					}
				}
			}
		}
		for(int q=1;q<=a;q++){
			haogandu=o[q]+wo[q]+ree[q]+haogandu;
		}
		
		cout<<haogandu;
		}
}
	return 0;
}
