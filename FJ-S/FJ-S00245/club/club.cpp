#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club,in","r",stdin);
	freopen("club,out","r",stdout);
	int t,n,a[1000],b[1000],c[1000],d[500],e[500],f[500],s1,s2,s3,s4,s5,s6,ax,bx,cx,a1[500],a2[500],a3[500];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			d[i]=a[i]*1;
			e[i]=a[i]*1;
			f[i]=a[i]*1;
		}
	}
	for(int i=0;i<n;i++){
		if(a1[i]==max(a[i],max(b[i],c[i]))){
			s1++;
			a1[i]+=a[i];
			if(s1>=n/2){
			for(int j=0;j<n;j++){
			a[j+1]=min(a[j],a[j+1]);
			if(j+1==n){
				ax=a[n-1]*1;
				for(int k=0;k<n;k++){
					if(ax=d[k]){
						s4=k;
					}
				}
				if(b[s4]==max(b[s4],c[s4])){
					s2++;
			a2[j]+=b[j];
				}else{
					s3++;
					a2[j]+=c[j];
				}
				a[n-1]=0;
				s1--;
			}
		}
	}
}else if(a2[i]==max(a[i],max(b[i],c[i]))){
			s2++;
			a2[i]+=b[i];
			if(s2>=n/2){
			for(int j=0;j<n;j++){
			a[j+1]=min(a[j],a[j+1]);
			if(j+1==n){
				bx=a[n-1]*1;
				for(int k=0;k<n;k++){
					if(bx=e[k]){
						s4=k;
					}
				}
				if(a[s4]==max(b[s4],c[s4])){
					
					s2++;
			a2[j]+=b[j];
				}
				a[n-1]=0;
				s1--;
			}
			}
		}
		}else if(a[i]==max(a[i],max(b[i],c[i]))){
			s3++;
			a3[i]+=c[i];
			if(s1>=n/2){
			for(int j=0;j<n;j++){
			a[j+1]=min(a[j],a[j+1]);
			if(j+1==n){
				ax=a[n-1]*1;
				for(int k=0;k<n;k++){
					if(ax=d[k]){
						s4=k;
					}
				}
				if(b[s6]==max(a[s6],b[s6])){
					s2++;
			a2[j]+=b[j];
				}else{
					s3++;
			a2[j]+=b[j];
				}
				a[n-1]=0;
				s1--;
			}
			}
		}
	}
}
	return 0;
}
