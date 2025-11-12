#include<bits/stdc++.h>
using namespace std;
long long t,n,za[100001][4],zd[100001],cd[100001],da,sl[4],ls[100001][2],ss[100001][2],xz[100001];
void px(int kt,int jw){
	if(kt==jw){
		return;
	}
	if(kt+1==jw){
		if(ss[kt][0]>ss[jw][0]){
			ls[kt][0]=ss[kt][0];
			ss[kt][0]=ss[jw][0];
			ss[jw][0]=ls[kt][0];
			ls[kt][1]=ss[kt][1];
			ss[kt][1]=ss[jw][1];
			ss[jw][1]=ls[kt][1];
		}
		return;
	}
	int i=kt,j,k=kt,zj=(kt+jw)/2;
	j=zj+1;
	px(kt,zj);
	px(j,jw);
	for(;i<=zj&&j<=jw;k++){
		if(ss[i][0]<ss[j][0]){
			ls[k][0]=ss[i][0];
			ls[k][1]=ss[i][1];
			i++;
		}
		else{
			ls[k][0]=ss[j][0];
			ls[k][1]=ss[j][1];
			j++;
		}
	}
	for(;i<=zj;i++,k++){
		ls[k][0]=ss[i][0];
		ls[k][1]=ss[i][1];
	}
	for(;j<=jw;j++,k++){
		ls[k][0]=ss[j][0];
		ls[k][1]=ss[j][1];
	}
	for(i=kt;i<=jw;i++){
		ss[i][0]=ls[i][0];
		ss[i][1]=ls[i][1];
	}
	return;
}
void cl(){
	da=0;
	for(int i=1;i<=3;i++){
		sl[i]=0;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>za[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(za[i][1]>=za[i][2]&&za[i][1]>=za[i][3]){
			zd[i]=1;
			if(za[i][2]>=za[i][3]){
				cd[i]=2;
			}
			else{
				cd[i]=3;
			}
		}
		else if(za[i][2]>=za[i][1]&&za[i][2]>=za[i][3]){
			zd[i]=2;
			if(za[i][1]>=za[i][3]){
				cd[i]=1;
			}
			else{
				cd[i]=3;
			}
		}
		else{
			zd[i]=3;
			if(za[i][1]>=za[i][2]){
				cd[i]=1;
			}
			else{
				cd[i]=2;
			}
		}
		ss[i][0]=za[i][zd[i]]-za[i][cd[i]];
		ss[i][1]=i;
		xz[i]=zd[i];
	}
//for(int i=1;i<=n;i++){
//	cout<<zd[i]<<"   "<<cd[i]<<"   "<<ss[i][0]<<"   "<<xz[i]<<endl;
//}
	for(int i=1;i<=n;i++){
		sl[zd[i]]++;
		da+=za[i][zd[i]];
	}
//cout<<da<<":::"<<endl;
	if(sl[1]<=n/2&&sl[2]<=n/2&&sl[3]<=n/2){
		cout<<da<<endl;
	}
	else{
		px(1,n);
//for(int i=1;i<=n;i++){
//	cout<<ss[i][0]<<"   "<<ss[i][1]<<endl;
//}
		for(int i=1;max(sl[1],max(sl[2],sl[3]))>n/2;i++){
			if(sl[xz[ss[i][1]]]>n/2){
				da-=ss[i][0];
				sl[xz[ss[i][1]]]--;
//cout<<i<<"   "<<ss[i][0]<<endl;
			}
		}
		cout<<da<<endl;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cl();
	}
	return 0;
} 
