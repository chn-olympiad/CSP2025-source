#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,nx,ny,nz;
long long ans;
bool flag=true;
struct stu{
	int x,y,z,sum,minus1,minus2,minus3,minus4,minussum,minus5,minus6,id;
}a[N];
bool cmp1(stu student1,stu student2){
	return student1.minus1>student2.minus1;
}
bool cmp2(stu student3,stu student4){
	if(student3.minus4!=student4.minus4) return student3.minus4>student4.minus4;
	if(student3.minus5!=student4.minus5) return student3.minus5>student4.minus5;
	else return student3.minus6>student4.minus6;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,nx=0,ny=0,nz=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].minus1=abs(a[i].y-a[i].x);
			a[i].minus2=abs(a[i].z-a[i].y);
			a[i].minus3=abs(a[i].z-a[i].x);
			a[i].minus4=max(max(a[i].minus1,a[i].minus2),a[i].minus3);
			a[i].minussum=a[i].minus1+a[i].minus2+a[i].minus3;
			a[i].minus6=min(min(a[i].minus1,a[i].minus2),a[i].minus3);
			a[i].minus5=a[i].minussum-a[i].minus4-a[i].minus6;
			a[i].id=i;
			a[i].sum=a[i].x+a[i].y+a[i].z;
			if(a[i].z!=0) flag=false;
		}
		if(flag){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++){
				if(a[i].x>=a[i].y && nx<n/2){
					nx++;
					ans=ans+a[i].x;
				}
				else{
					ny++;
					ans=ans+a[i].y;
				}
			}
			cout<<ans<<endl;
		}
		else{
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++){
				int maxa=max(max(a[i].x,a[i].y),a[i].z),mina=min(min(a[i].x,a[i].y),a[i].z),normal=a[i].x+a[i].y+a[i].z-maxa-mina;
				if(maxa==a[i].z){
					if(nz<n/2){
						nz++;
						ans=ans+maxa;
					}
					else if(normal==a[i].y){
						ny++;
						ans=ans+normal;
					}
					else{
						nx++;
						ans=ans+normal;
					}
				}
				if(maxa==a[i].y){
					if(ny<n/2){
						ny++;
						ans=ans+maxa;
					}
					else if(normal==a[i].z){
						nz++;
						ans=ans+normal;
					}
					else{
						nx++;
						ans=ans+normal;
					}
				}
				if(maxa==a[i].x){
					if(nx<n/2){
						nx++;
						ans=ans+maxa;
					}
					else if(normal==a[i].z){
						nz++;
						ans=ans+normal;
					}
					else{
						ny++;
						ans=ans+normal;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
