#include<bits/stdc++.h>
using namespace std;
int t,n,ma=0,mb=0,mc=0,al=0,bl=0,cl=0,an=0,bn=0,cn=0,sum=0;
void fenpei(int a[],int b[],int c[]){
	while(an<=n/2||bn<=n/2||cn<=n/2){
		if(an>n/2){
			for(int i=0;i<n;i++){
				if(b[i])if(mb<b[i]){mb=b[i];bl=i;}
				if(c[i])if(mc<c[i]){mc=c[i];cl=i;}}
			if(cl==bl){
				if(mc<mb){
					bn++;sum+=mb;}
				else{
					cn++;sum+=mc;}
				a[bl]=0;b[bl]=0;c[bl]=0;}
			else{
				bn++;cn++;sum=sum+mb+mc;b[bl]=0;c[cl]=0;}
			ma=0;mb=0;mc=0;al=0;bl=0;cl=0;
			continue;
		}
		else if(bn>n/2){
			for(int i=0;i<n;i++){
				if(a[i])if(ma<a[i]){ma=a[i];al=i;}
				if(c[i])if(mc<c[i]){mc=c[i];cl=i;}
		}
			if(al==cl){
				if(ma<mc){
					cn++;sum+=mc;}
				else{
					an++;sum+=ma;}
				a[bl]=0;b[bl]=0;c[bl]=0;ma=0;mb=0;mc=0;al=0;bl=0;cl=0;}
			else{
				an++;cn++;sum=sum+ma+mb+mc;a[al]=0;b[bl]=0;c[cl]=0;}
				ma=0;mb=0;mc=0;al=0;bl=0;cl=0;continue;}
		else if(cn>n/2){
			for(int i=0;i<n;i++){
				if(a[i])if(ma<a[i]){ma=a[i];al=i;}
				if(b[i])if(mb<b[i]){mb=b[i];bl=i;}}
			if(al==bl){
				if(ma<mb){
					bn++;sum+=mb;}
				else{
					an++;sum+=ma;}
				a[al]=0;b[al]=0;c[al]=0;}
			else{
				an++;bn++;sum=sum+ma+mb+mc;a[al]=0;b[bl]=0;c[cl]=0;}
			ma=0;mb=0;mc=0;al=0;bl=0;cl=0;continue;}
		else{
			for(int i=0;i<n;i++){
				if(a[i])if(ma<a[i]){ma=a[i];al=i;}
				if(b[i])if(mb<b[i]){mb=b[i];bl=i;}
				if(c[i])if(mc<c[i]){mc=c[i];cl=i;}
			}
			if(al==bl){
				if(ma<mb){
					bn++;sum+=mb;	}
				else{
					an++;sum+=ma;}
				a[al]=0;b[al]=0;c[al]=0;
			}
			else if(cl==bl){
				if(mc<mb){
					bn++;sum+=mb;
				}
				else{
					cn++;sum+=mc;
				}
				a[bl]=0;b[bl]=0;c[bl]=0;
			}
			else if(al==cl){
				if(ma<mc){
					cn++;sum+=mc;
				}
				else{
					an++;sum+=ma;
				}
				a[bl]=0;b[bl]=0;c[bl]=0;
			}
			else{
				an++;bn++;cn++;sum=sum+ma+mb+mc;a[al]=0;b[bl]=0;c[cl]=0;}
		ma=0;mb=0;mc=0;al=0;bl=0;cl=0;continue;}
	}
	cout<<sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int a[n+1],b[n+1],c[n+1];
		for(int j=0;j<n;j++){
			scanf("%d",&a[j]);scanf("%d",&b[j]);scanf("%d",&c[j]);
		}
		fenpei(a,b,c);
	}
	return 0;
}
