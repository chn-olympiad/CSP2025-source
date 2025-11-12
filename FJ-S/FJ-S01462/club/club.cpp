#include<bits/stdc++.h>
using namespace std;
int n,t,sum,ant,big1=-1,big2=-1,big3=-1,s1=0,s2=0,s3=0,ii=1,jj=0,ll=0;
bool a1[10005],a2[10005],a3[10005];
bool b1[10005],b2[10005],b3[10005];
bool cmp(int x,int y){
	if(x>y) return true;
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
		}
		for(int j=1;j<=n;j++){
			if(a1[j]>big2&&a1[j]!=true){
				ii++;
				big1=a1[j];
				b1[ii]=a1[j];
				a1[j]=true;
				s1+=a1[j]; 
			}
			if(a2[j]>big2&&a2[j]!=true){
				jj++;
				big2=a2[j];
				b2[jj]=a2[j];
				a2[j]=true;
				s2+=a2[j];
			}
			if(a3[j]>big2&&a3[j]!=true){
				ll++;
				big3=a3[j];
				b3[ll]=a3[j];
				a3[j]=true;
				s3+=a3[j];
			}
		}
		cout<<s1+s2+s3<<endl;
	} 
	
	return 0;
} 

