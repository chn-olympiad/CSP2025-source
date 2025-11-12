#include<bits/stdc++.h>
using namespace std;
const int N=100006;
int t,n[5],ii[N][3],a[N],b[N];
int v[N],v0[N],v1[N],v2[N];
int vf0[5][N/2],vf1[5][N/2],vf2[5][N/2];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n[i];
		for(int j=0;j<n[i];j++){
			cin>>ii[j][0]>>ii[j][1]>>ii[j][2];
			a[j]=max(ii[j][0],max(ii[j][1],ii[j][2]));
		}
		for(int j=0,s,tem0=0,tem1=0,tem2=0;j<n[i];j++){
			if(a[j]==ii[j][0]){
				vf0[i][tem0]=v0[i];
				tem0++;
				v0[i]+=a[j];
			}
			else if(a[j]==ii[j][1]){
					vf1[i][tem1]=v1[i];
					tem1++;
					v1[i]+=a[j];
				}
			else if(a[j]==ii[j][2]){
					vf2[i][tem2]=v2[i];
					tem2++;
					v2[i]+=a[j];
				}
			s=tem0+tem1+tem2;
			if(tem0>n[i]/2){
				tem0--;
				vf0[i][tem0]=v0[i];
				for(int k=0;k<s;k++){
					if((ii[j][0]>=ii[j][1]&&ii[j][0]<=ii[j][2])||(ii[j][0]>=ii[j][2]&&ii[j][0]<=ii[j][1])){
						b[i]=max(b[i],ii[j][0]);
					}
					if((ii[j][1]>=ii[j][0]&&ii[j][1]<=ii[j][2])||(ii[j][1]>=ii[j][2]&&ii[j][1]<=ii[j][0])){
						b[i]=max(b[i],ii[j][1]);
					}
					if((ii[j][2]>=ii[j][0]&&ii[j][2]<=ii[j][1])||(ii[j][2]>=ii[j][1]&&ii[j][2]<=ii[j][0])){
						b[i]=max(b[i],ii[j][2]);
					}
				}
				tem0++;
				v0[i]-=vf0[i][tem0];
				if(b[i]==ii[j][0])v0[i]+=ii[j][0];
				else if(b[i]==ii[j][1])v1[i]+=ii[j][1];
				else if(b[i]==ii[j][2])v2[i]+=ii[j][2];
				continue;
			}
			if(tem1>n[i]/2){
				tem1--;
				vf1[i][tem1]=v1[i];
				for(int k=0;k<s;k++){
					if((ii[j][0]>=ii[j][1]&&ii[j][0]<=ii[j][2])||(ii[j][0]>=ii[j][2]&&ii[j][0]<=ii[j][1])){
						b[i]=max(b[i],ii[j][0]);
					}
					if((ii[j][1]>=ii[j][0]&&ii[j][1]<=ii[j][2])||(ii[j][1]>=ii[j][2]&&ii[j][1]<=ii[j][0])){
						b[i]=max(b[i],ii[j][1]);
					}
					if((ii[j][2]>=ii[j][0]&&ii[j][2]<=ii[j][1])||(ii[j][2]>=ii[j][1]&&ii[j][2]<=ii[j][0])){
						b[i]=max(b[i],ii[j][2]);
					}
				}
				tem1++;
				v1[i]-=vf1[i][tem1];
				if(b[i]==ii[j][0])v0[i]+=ii[j][0];
				else if(b[i]==ii[j][1])v1[i]+=ii[j][1];
				else if(b[i]==ii[j][2])v2[i]+=ii[j][2];
				continue;
			}
			if(tem2>n[i]/2){
				tem2--;
				vf2[i][tem2]=v2[i];
				for(int k=0;k<s;k++){
					if((ii[j][0]>=ii[j][1]&&ii[j][0]<=ii[j][2])||(ii[j][0]>=ii[j][2]&&ii[j][0]<=ii[j][1])){
						b[i]=max(b[i],ii[j][0]);
					}
					if((ii[j][1]>=ii[j][0]&&ii[j][1]<=ii[j][2])||(ii[j][1]>=ii[j][2]&&ii[j][1]<=ii[j][0])){
						b[i]=max(b[i],ii[j][1]);
					}
					if((ii[j][2]>=ii[j][0]&&ii[j][2]<=ii[j][1])||(ii[j][2]>=ii[j][1]&&ii[j][2]<=ii[j][0])){
						b[i]=max(b[i],ii[j][2]);
					}
				}
				tem2++;
				v2[i]-=vf2[i][tem2];
				if(b[i]==ii[j][0])v0[i]+=ii[j][0];
				else if(b[i]==ii[j][1])v1[i]+=ii[j][1];
				else if(b[i]==ii[j][2])v2[i]+=ii[j][2];
				continue;
			}
		}
		v[i]=v0[i]+v1[i]+v2[i];
		cout<<v[i]<<endl;
	}
	return 0;
}