#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][4],ans,c1,c2,c3,b[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		c1=0,c2=0,c3=0,ans=0;
		for(int i=0;i<n+1;i++){
			b[i]=0;
		}
		for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]) {
		b[i]=a[i][0];
		if(c1>=n/2){
			for(int j=i;j>=0;j--){
				if(b[j]+max(a[i][1],a[i][2])<b[i]+max(a[j][1],a[i][2])){
					if(a[j][1]>=a[j][2]) {
					b[j]=a[j][1];
					c1-=1;
					c2+=1;}
					else{
					b[j]=a[j][2];
					c1-=1;
					c3+=1;}
				}
			}
		}
		else c1+=1;
	}
		else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2]) {
		b[i]=a[i][1];
		if(c2>=n/2){
			for(int j=i;j>=0;j--){
				if(b[j]+max(a[i][0],a[i][2])<b[i]+max(a[j][0],a[i][2])){
					if(a[j][0]>=a[j][2]) {
					b[j]=a[j][0];
					c2-=1;
					c1+=1;}
					else {
					b[j]=a[j][2];
					c2-=1;
					c3+=1;}
				}
			}
		}
		else c2+=1;}
		else if(a[i][2]>=a[i][0] && a[i][2]>=a[i][1]) {
		b[i]=a[i][2];
		if(c3>=n/2){
			for(int j=i;j>=0;j--){
				if(b[j]+max(a[i][1],a[i][0])<b[i]+max(a[j][1],a[i][0])){
					if(a[j][0]>=a[j][1])
					{b[j]=a[j][0];
					c3-=1;
					c1+=1;}
					else {
					b[j]=a[j][1];
					c3-=1;
					c2+=1;
				}
			}
		}
		}
		else c3+=1;}
	}
		for(int i=0;i<n;i++){
			ans+=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
