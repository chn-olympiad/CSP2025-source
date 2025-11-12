#include<bits/stdc++.h>
using namespace std;
struct node{
	int one,two,thr,cha;
}b[100001],s[100001];
int k,a[1000001],t[1000001];
int sum,q=1,v;

int f(int a,int b,int c){
	if(a>=b&&a>=c)	return a;
	else if(b>=a&&b>=c)	return b;
	else if(c>=a&&c>=b)	return c;
}

int g(int a,int b,int c){
	if((a>=b&&a<=c)||(a<=b&&a>=c))	return a;
	else if((b>=a&&b<=c)||(b<=a&&b>=c))	return b;
	else if((c>=b&&c<=a)||(c<=b&&c>=a))	return c;	
}

int cmp(int a,int b){
	return a<=b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>k;
	for(int i=1;i<=k;i++){
		sum=0,s[0].one=0,s[0].two=0,s[0].thr=0;
		cin>>a[i];
		for(int j=1;j<=a[i];j++){
			cin>>b[j].one>>b[j].two>>b[j].thr;
		}
		for(int j=1;j<=a[i];j++){
			sum=sum+f(b[j].one,b[j].two,b[j].thr);
			if(f(b[j].one,b[j].two,b[j].thr)==b[j].one)	s[0].one++;
			else if(f(b[j].one,b[j].two,b[j].thr)==b[j].two)	s[0].two++;
			else if(f(b[j].one,b[j].two,b[j].thr)==b[j].thr)	s[0].thr++;
		}
		if(f(s[0].one,s[0].two,s[0].thr)<=(a[i]/2))	{
		cout<<sum<<endl;	
		}
		
		else{
			q=0;
			v=0;
			if(f(s[0].one,s[0].two,s[0].thr)==s[0].one)	{
				for(int j=1;j<=a[i];j++){
					if(f(b[j].one,b[j].two,b[j].thr)==b[j].one)	{
					v++;	
					t[v]=b[j].one-max(b[j].two,b[j].thr);
						
					}
				}
				sort(t+1,t+1+v,cmp);
				q=0;
				while((s[0].one)>a[i]/2){
					q++;
					s[0].one=s[0].one-1;
					sum=sum-t[q];
				}
			}
			else if(f(s[0].one,s[0].two,s[0].thr)==s[0].two){
				for(int j=1;j<=a[i];j++){
					if(f(b[j].one,b[j].two,b[j].thr)==b[j].two)	{
						v++;
					t[v]=b[j].two-max(b[j].one,b[j].thr);	
					}
				}
				sort(t+1,t+1+v,cmp);
				q=0;
				while((s[0].two)>a[i]/2){
					q++;
					s[0].two=s[0].two-1;
					sum=sum-t[q];
				}
			}
			else if(f(s[0].one,s[0].two,s[0].thr)==s[0].thr){
				for(int j=1;j<=a[i];j++){
					if(f(b[j].one,b[j].two,b[j].thr)==b[j].thr)	{
					v++;	
					t[v]=b[j].thr-max(b[j].two,b[j].one);
					}
				}
				sort(t+1,t+1+v,cmp);
				q=0;
				while((s[0].thr)>a[i]/2){
					q++;
					s[0].thr=s[0].thr-1;
					sum=sum-t[q];
				}
			}
			cout<<sum<<endl;
		}
	}
	
	return 0;
}
