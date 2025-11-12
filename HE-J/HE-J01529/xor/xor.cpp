#include<bits/stdc++.h>
using namespace std;
long long a,b,c[600005],qzh[600005],ans,y;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//Òì»ò£º^ 
	cin>>a>>b;
	cin>>c[1];
	qzh[1]=c[1];
	//cout<<qzh[1];
	for(int i=2;i<=a;i++){
		cin>>c[i];
		qzh[i]=qzh[i-1]^c[i];
		//cout<<qzh[i]<<" ";
	}
	for(int i=1;i<=a;i++){
		for(int u=i;u<=a;u++){
			if(i!=1){
				if((qzh[u]^qzh[i-1])==b){
					ans++;//cout<<qzh[u]<<" "<<qzh[i-1]<<" "<<(qzh[u]^qzh[i-1])<<" "<<i<<" "<<u<<endl;
					y=u;
					break;
					//u=a;
				}
			}
			if(i==1){
				if(qzh[u]==b){
					ans++;//cout<<i<<u<<endl;
					y=u;
					break;
					//u=a;
				}
			}
		}
	 	if(y!=0)i=y;
	 	y=0;
	}
	cout<<ans;
	return 0;
}
