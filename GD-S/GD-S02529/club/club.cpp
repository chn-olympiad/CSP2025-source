#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int s,n,l[100000][3],e,m[100000],d,a[3],o[100000];
	cin>>s;
	for(int iii=0;iii<s;iii++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>l[i][0]>>l[i][1]>>l[i][2];
		}
		m[0]=3;
		for(int i=1;i<n;i++){
			m[i]=m[i-1]*3;
		}
		d=0;
		for(int ii=0;ii<m[n];ii++){
			e=0;
			a[0]=0;
	    	a[1]=0;
		    a[2]=0;
			o[n]++;
			for(int j=n;j>0;j--){
				if(o[j]==3){
					o[j-1]++;
					o[j]=0;
				}
				e=l[j][o[j]]+e;
				if(o[j]==0){
					a[0]++;
				}
				if(o[j]==1){
					a[1]++;
				}
				if(o[j]==2){
					a[2]++;
				}
				
			}
			if(a[0]<=n/2 and a[1]<=n/2){
				if(a[2]<=n/2 and d<e){
					d=e;
				}
			}
		}
		cout<<d;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
