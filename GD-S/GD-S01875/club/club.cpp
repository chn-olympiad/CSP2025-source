#include<bits/stdc++.h>
using namespace std;
const int N=100001;
long long a[N][4],b[N][3];
long long n,mx1=0,mx2=0,c[4],cnt[4];
void pd(int c){
	int mx=0,mx3;
	for(int i=1;i<=n;i++){
		if(b[i][1]==c){
			if(a[i][b[i][2]]>=mx){
				mx=b[i][2];
				mx3=i;
			}
		}
	}
	b[mx3][1]=mx;
	cnt[c]--;
	cnt[mx]++;
}
long long happy(int n){
	mx1=mx2=cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++){
		mx1=1;
		for(int j=1;j<=3;j++){
	    	c[j]=a[i][j];
			if(a[i][j]>a[i][mx1]){
				mx1=j;
			}
		}
		c[mx1]=-1;
		mx2=1;
		for(int j=1;j<=3;j++){
			if(c[j]>c[mx2]){
				mx2=j;
			}
		}
		b[i][1]=mx1;
		b[i][2]=mx2;
		if(mx1==1) cnt[1]++;
		if(mx1==2) cnt[2]++;
		if(mx1==3) cnt[3]++;
	}
	while(1){
		if(cnt[1]>n/2){
	    	pd(1);
    	}else{
    		if(cnt[2]>n/2){
    			pd(2);
			}else{
				if(cnt[3]>n/2){
					pd(3);
				}else{
					break;
				}
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i][b[i][1]];
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		cout<<happy(n)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
