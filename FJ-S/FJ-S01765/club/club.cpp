#include<bits/stdc++.h>
using namespace std;
long long h,t,a,b,n,m,o[100100][5],oo[100100][5],p[100100],v[100100],u[100100];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>m;
	for(int ii=1;ii<=m;ii++){
		h=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			u[i]=0;
		for(int i=1;i<=n;i++){
			cin>>o[i][1]>>o[i][2]>>o[i][3];	
			oo[i][1]=o[i][1];oo[i][2]=o[i][2];oo[i][3]=o[i][3];		
		}
		for(int i=1;i<=n;i++){
			a=max(oo[i][1],max(oo[i][2],oo[i][3]));
			if(oo[i][1]==a)
				oo[i][1]=-1;
			else if(oo[i][2]==a)
				oo[i][2]=-1;
			else if(oo[i][3]==a)
				oo[i][3]=-1;
			b=max(oo[i][1],max(oo[i][2],oo[i][3]));
			p[i]=a-b;
		}	
		t=0;
		for(int i=1;i<=n;i++){
			if(max(o[i][1],max(o[i][2],o[i][3]))==o[i][1]&&u[i]==0){
				h+=o[i][1];
				u[i]=1;
				t++;
				v[t]=p[i];
			}
		}
		if(t>n/2){
			sort(v+1,v+t+1);
			t-=n/2;
			for(int i=1;i<=t;i++)
				h-=v[i];
		}	
		t=0;
		for(int i=1;i<=n;i++){
			if(max(o[i][1],max(o[i][2],o[i][3]))==o[i][2]&&u[i]==0){
				h+=o[i][2];
				u[i]=1;
				t++;
				v[t]=p[i];
			}
		}
		if(t>n/2){
			sort(v+1,v+t+1);
			t-=n/2;
			for(int i=1;i<=t;i++)
				h-=v[i];
		}	
		t=0;
		for(int i=1;i<=n;i++){
			if(max(o[i][1],max(o[i][2],o[i][3]))==o[i][3]&&u[i]==0){
				h+=o[i][3];
				u[i]=1;
				t++;
				v[t]=p[i];
			}
		}
		if(t>n/2){
			sort(v+1,v+t+1);
			t-=n/2;
			for(int i=1;i<=t;i++)
				h-=v[i];
		}	
		cout<<h<<endl;
	}
	return 0;
}