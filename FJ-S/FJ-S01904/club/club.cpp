#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		int a1[n],a2[n],a3[n],y[3],ma[n],ans=0;
		for(int i=0;i<n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(max(max(a1[i],a2[i]),a3[i])==a1[i]){
				ma[i]=1;
			}
			else if(max(max(a1[i],a2[i]),a3[i])==a2[i]){
				ma[i]=2;
			}
			else if(max(max(a1[i],a2[i]),a3[i])==a3[i]){
				ma[i]=3;
			}
		}
		for(int i=0;i<n;i++){
			y[ma[i]]++;
			if(y[ma[i]]>n/2){
				if(ma[i]==1){
					a1[i]=0;
				}
				else if(ma[i]==2){
					a2[i]=0;
				}
				else if(ma[i]==3){
					a2[i]=0;
				}
			}
			ans=ans+max(max(a1[i],a2[i]),a3[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
