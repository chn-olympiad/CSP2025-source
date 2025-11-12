#include<bits/stdc++.h>
using namespace std;
int zd1[100001],zd2[100001],zd3[100001],js1[100001],js2[100001],js3[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ms=0,rs1=0,rs2=0,rs3=0,j,l,s1,s2,s3;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ms=0,rs1=0,rs2=0,rs3=0;
		for(j=1;j<=n;j++){	
			cin>>s1>>s2>>s3;
			if(s1>s2&&s1>s3){
				rs1++;
				zd1[rs1]=s1;
				ms+=s1;
				js1[rs1]=s1-max(s2,s3);
			}else if(s2>s3){
				rs2++;
				zd2[rs2]=s2;
				ms+=s2;
				js2[rs2]=s2-max(s1,s3);
			}else{
				rs3++;
				zd3[rs3]=s3;
				ms+=s3;
				js3[rs3]=s3-max(s1,s2);
			}
		}
		l=n/2;
		if(rs1>l){
			sort(js1+1,js1+rs1+1);
			for(j=1;j<=rs1-l;j++){
				ms-=js1[j];
			}
		}
		if(rs2>l){
			sort(js2+1,js2+rs2+1);
			for(j=1;j<=rs2-l;j++){
				ms-=js2[j];
			}
		}
		if(rs3>l){
			sort(js3+1,js3+rs3+1);
			for(j=1;j<=rs2-l;j++){
				ms-=js3[j];
			}
		}
		cout<<ms<<endl;
	}
	return 0;
}