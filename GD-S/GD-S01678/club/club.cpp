#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e5+10;
int a[N],b[N],c[N],d[N],e[N],f[N];
int s[10];
int fp(int n){
long long ans=0;
int cnt1=0,cnt2=0,cnt3=0;
int s1=0,s2=0,s3=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=b[i]&&a[i]>=c[i]){
			s1++;
			d[s1]=i;
			cnt1++;
		}else if(a[i]<b[i]&&b[i]>=c[i]){
			s2++;
			e[s2]=i;
			cnt2++;
		}else if(c[i]>b[i]&&a[i]<c[i]){
			s3++;
			f[s3]=i;
			cnt3++;
		}	
	}
	while(cnt1>n/2){
		int min=9999999,num=0;
		for(int i=1;i<=cnt1;i++){
			if(min>=a[d[i]]){
				min=a[d[i]];
				num=i;
			}
		}
		cnt1--;
		if(b[d[num]]>=c[d[num]]){
			cnt2++;
			e[cnt2]=d[num];
			
		}else{
			cnt3++;
			f[cnt3]=d[num];
			
		}
		d[num]=0;
	}
	while(cnt2>n/2){
		int min=9999999,num=0;
		for(int i=1;i<=cnt2;i++){
			if(min>=b[e[i]]){
				min=b[e[i]];
				num=i;
			}
		}
		cnt2--;
		if(a[e[num]]>=c[e[num]]){
			cnt1++;
			d[cnt1]=e[num];
			
		}else{
			cnt3++;
			f[cnt3]=e[num];
			
		}
		e[num]=0;
	}
	while(cnt3>n/2){
		int min=9999999,num=0;
		for(int i=1;i<=cnt3;i++){
			if(min>=c[f[i]]){
				min=c[f[i]];
				num=i;
			}
		}
		cnt3--;
		if(a[f[num]]>=b[f[num]]){
			cnt1++;
			d[cnt1]=f[num];
			
		}else{
			cnt2++;
			e[cnt2]=f[num];
			
		}
		f[num]=0;
	}
	for(int i=1;i<=cnt1+n/2;i++){
		if(d[i]==0)i++;
		ans+=a[d[i]];
	}
	for(int i=1;i<=cnt2+n/2;i++){
		if(e[i]==0)i++;
		ans+=b[e[i]];
	}
	for(int i=1;i<=cnt3+n/2;i++){
		if(f[i]==0)i++;
		ans+=c[f[i]];
	}
	for(int i=1;i<=n+100;i++){
		a[i]=b[i]=c[i]=d[i]=e[i]=f[i]=0;
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int k=0;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			int x,y,z;
			cin>>x>>y>>z;
			a[j]=x,b[j]=y,c[j]=z;
		}
		
		cout<<fp(n)<<endl;
	}
	return 0;
} 


