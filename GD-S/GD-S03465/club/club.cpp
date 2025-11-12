#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001],c[100001],a1,b1,c1,n,t,s;
bool cc(long long a,long long b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		a1=b1=c1=s=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				s+=a[i];
				a1++;
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				s+=b[i];
				b1++;
			}
			else{
				s+=c[i];
				c1++;
			}
		}
		if(a1>n/2){
			a1-=n/2;
			int i=0;
			for(int i=1;i<=n;i++)a[i]=max(b[i],c[i])-a[i];
			sort(a+1,a+n+1,cc);
			while(a1!=0){
				i++;
				if(a[i]<=0){
					s+=a[i];
					a1--;
				}
			}
		}
		else if(b1>n/2){
			b1-=n/2;
			int i=0;
			for(int i=1;i<=n;i++)b[i]=max(a[i],c[i])-b[i];
			sort(b+1,b+n+1,cc);
			while(b1!=0){
				i++;
				if(b[i]<=0){
					s+=b[i];
					b1--;
				}
			}
		}
		else if(c1>n/2){
			c1-=n/2;
			int i=0;
			for(int i=1;i<=n;i++)c[i]=max(a[i],b[i])-c[i];
			sort(c+1,c+n+1,cc);
			while(c1!=0){
				i++;
				if(c[i]<=0){
					s+=c[i];
					c1--;
				}
			}
		}
		cout<<s<<endl;
	}
		
	return 0;
} 

