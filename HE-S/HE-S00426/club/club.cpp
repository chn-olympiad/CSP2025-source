#include<iostream>
using namespace std;
int m[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int p=0;p<n;p++){
		int s;
		cin>>s;
		int q[s][3];
		int b[s];
		for(int i=0;i<s;i++){
			for(int j=0;j<3;j++){	
			cin>>q[i][j];
		}
	}
	for(int i=0;i<s;i++){
		for(int j=0;j<3;j++){
	    	if(m[j]<s/2){
	    		b[i]=q[i][0];
				b[i]=max(b[i],q[i][1]);
				b[i]=max(b[i],q[i][2]);
				m[j]++;
			}
			else{
				if(m[j]>=s/2){
					q[i][j]=0;
				}
				b[i]=q[i][j];
			    if(b[i]<q[i][1]){
			    	b[i]=q[i][1];
				}
				else if(b[i]<q[i][2]){
					b[i]=q[i][2];
				}
				m[j]++;
			}	
		}
	}
	int ans=0;
	for(int i=0;i<s;i++){
		ans=ans+b[i];
	}
	cout<<ans;
} 
	return 0;
} 
