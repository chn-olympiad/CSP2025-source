//GZ-S00406 六盘水市知见外国学校 覃圣超 
#include<bits/stdc++.h>
using namespace std;
int a[1001][3],q[1001][1001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,s=0,b=10000,c=110000,v=0,t=10000;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<m+1;j++){
			cin>>q[i][j];
		} 	
		if(c>q[i][0]) c=q[i][0];
	} 
    while(v<m*1.0/2){
    	for(int i=0;i<m;i++){
    		if(b>a[i][2]) {
    			b=a[i][2];
			}
		}
		s=s+b;
    	v+=1;
	}
	for(int i=0;i<m;i++){
		if(a[i][2]!=b){
			if(t>a[i][2]) t=a[i][2];
		}
	}
	s=s+(t-b);
	v=0;
	t=10000;
	b=10000;
	while(v<m*1.0/2){
		for(int i=1;i<m+1;i++){
			if(t>q[c][i]) t=q[c][i];
		}
		s=s+t;
		v+=1;
	}
	for(int i=1;i<m+1;i++){
		if(q[c][i]!=t){
			if(b>q[c][i]){
				b=q[c][i];
			}
		}
	}
	s=s+(b-t);
	s=s+c;
	cout<<s;
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
