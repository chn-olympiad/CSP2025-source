#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int a,b,c;
int num1,num2,num3;
int t1[100010];
int t2[100010];
int t3[100010];
int ans;

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int ch[n+10];
		for(int j=1;j<=n;j++){
			cin>>t1[j]>>t2[j]>>t3[j];
			if(t1[j]>=t2[j] and t3[j]<=t1[j]){
				ch[j]=1;
			}
			else{
				if(t2[j]>=t1[j] and t3[j]<=t2[j]){
					ch[j]=2;
				}
				else{
					ch[j]=3;
				}
			}
		} 
		
		for(int k=1;k<=n;k++){
			if(ch[k]==1){
				ans+=t1[k];
			}
			if(ch[k]==2){
				ans+=t2[k];
			}
			if(ch[k]==3){
				ans+=t3[k];
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
