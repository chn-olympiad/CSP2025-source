#include<bits/stdc++.h>
using namespace std;
int n,m,p,k;
int l[50100][50];
int c[50],hk[10000][5];
int a,b;
int r=0,h=1;
int ans,cf=1;
int be,ed;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		cin>>l[i][0];
		m=l[i][0];
		r=0;
		while(m>0){
			a=m/2;
			b=m%2;
			m=a;
			l[i][40-r]=b;
			r++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1+i;j<=n;j++){
			if(j==i+1){
				for(int t=40;t>20;t++){
					if(l[i][t]==l[j][t]){
						c[t]=0;
					}else{
						c[t]=1;
					}
				}
				h=1;
				for(int t=40;t>20;t++){
					if(t==40){
						ans+=c[t]*h;
					}else{
						ans+=c[t]*h*2;
					}
					h++;
				}
				if(ans==k){
					hk[cf][1]=i;
					hk[cf][2]=j;
					cf++;
					break;
				}
			}else{
				for(int t=40;t>20;t++){
					if(c[t]==l[j][t]){
						c[t]=0;
					}else{
						c[t]=1;
					}
				}
				h=1;
				for(int t=40;t>20;t++){
					if(t==40){
						ans+=c[t]*h;
					}else{
						ans+=c[t]*h*2;
					}
					h++;
				}
				if(ans==k){
					hk[cf][1]=i;
					hk[cf][2]=j;
					cf++;
					break;
				}
			}
		}
	}
	
	cout<<cf;





	return 0;
}
