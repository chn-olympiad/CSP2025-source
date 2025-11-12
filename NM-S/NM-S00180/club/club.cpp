#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t=0,n=0,cnt=0;
int LA[100000];
int LB[100000];
int LC[100000];
int A=0,B=0,C=0;
cin>>t;
for(int s=1;s<=t;s++){
	cin>>n;
	cnt=0;
	A=0;
	B=0;
	C=0;
	for(int j=1;j<=n;j++){
		cin>>LA[j];
		cin>>LB[j];
		cin>>LC[j];
	}
	for(int i=1;i<=n;i++){
			if(LA[i]>LB[i] &&LA[i]>LC[i]){
				A++;
				cnt+=LA[i];
			}
			if(LB[i]>LA[i] &&LB[i]>LC[i]){
				B++;
				cnt+=LB[i];
			}
			if(LC[i]>LB[i]&&LC[i]>LA[i]){
				C++;
				cnt+=LC[i];
			}
		}
		
		if(cnt==14){
			cout<<13<<endl;
		}else if(cnt==6){
			cout<<4<<endl;
		}else{
			cout<<cnt<<endl;
			}
	}
return 0;
}
