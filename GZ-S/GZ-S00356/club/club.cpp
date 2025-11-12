//GZ-S00356 遵义市新浦中学 童俊铭 
#include <bits/stdc++.h>
using namespace std;
int main(){ 
	int t,n=1,m=0,s1=0,s2=0,s3=0,h=0,u=0,b=0;
	cin>>t;
	int c[t];
	for(int k=1;k<=t;k++){
		cin>>n;
		int a[n][3];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];		    
			}
			m=max(a[i][1],a[i][2]);
			m=max(m,a[i][3]);
			h+=m; 
			if(m==a[i][1]){
				s1++;
			}
			if(m==a[i][2]){
				s2++;
			}
			if(m==a[i][3]){
				s3++;
			}	
		}
		if(s1>n/2){
			h=0;
			    int e=0,o=0;
				for(int w=1;w<=n+1;w++){
					e=max(e,a[w][1]);
				}
				for(int w=1;w<=n+1;w++){
					if(e==a[w][1]){
						u=w;
					}
				}
				for(int w=1;w<=n+1;w++){
					if(a[w][1]<=e){
						o=a[w][1];
						o=max(o,a[w][1]);
					}
				}
				for(int w=1;w<=n+1;w++){
					if(o==a[w][1]&&w!=e){
						b=w;
					}
				}
				for(int i=1;i<=n;i++){
					m=max(a[i][1],a[i][2]);
			        m=max(m,a[i][3]);
			        if(i==b){
			        	m+=o;
			        	break;
					}
					if(i==u){
			        	m+=e;
			        	break;
					}
			        h+=m; 
				}
			}
			if(s2>n/2){
				h=0;
			    int e=0,o=0;
				for(int w=1;w<=n;w++){
					e=max(e,a[w][2]);
				}
				for(int w=1;w<=n;w++){
					if(e==a[w][2]){
						u=w;
					}
				}
				for(int w=1;w<=n;w++){
					if(a[w][2]<=e){
						o=a[w][2];
						o=max(o,a[w][2]);
					}
				}
				for(int w=1;w<=n;w++){
					if(o==a[w][2]&&w!=e){
						b=w;
					}
				}
				for(int i=1;i<=n;i++){
					m=max(a[i][1],a[i][2]);
			        m=max(m,a[i][3]);
			        if(i==b){
			        	m+=o;
			        	break;
					}
					if(i==u){
			        	m+=e;
			        	break;
					}
			        h+=m; 
				}
			}
			if(s3>n/2){
				h=0;
			    int e=0,o=0;
				for(int w=1;w<=n;w++){
					e=max(e,a[w][3]);
				}
				for(int w=1;w<=n;w++){
					if(e==a[w][3]){
						u=w;
					}
				}
				for(int w=1;w<=n;w++){
					if(a[w][3]<=e){
						o=a[w][3];
						o=max(o,a[w][3]);
					}
				}
				for(int w=1;w<=n;w++){
					if(o==a[w][3]&&w!=e){
						b=w;
					}
				}
				for(int i=1;i<=n;i++){
					m=max(a[i][1],a[i][2]);
			        m=max(m,a[i][3]);
			        if(i==b){
			        	m+=o;
			        	break;
					}
					if(i==u){
			        	m+=e;
			        	break;
					}
			        h+=m; 
				}
			}
		cout<<h;
		m=0,s1=0,s2=0,s3=0,h=0;
	}
	return 0;
}
