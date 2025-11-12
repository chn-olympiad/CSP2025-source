#include<bits/stdc++.h>
using namespace std;
long long t,n,a[10005],b[10005],c[10005],a2[10005],b2[10005],c2[10005],minx0[10005],minx1[10005],minx2[10005],m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long a3=0,b3=0,c3=0,a1=0,b1=0,c1=0,s=0,aa=0,bb=0,cc=0;
		for(int i=0;i<n;i++){a2[i]=0,b2[i]=0,c2[i]=0;}
		cin>>n;
		for(int i=0;i<n;i++)minx2[i]=0,minx1[i]=0,minx0[i]=0;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			m=max(max(a[i],b[i]),c[i]);
			if(a[i]==m){a1++,s+=a[i];}
			else if(b[i]==m){b1++,s+=b[i];}
			else if(c[i]==m){c1++,s+=c[i];}
			if((a[i]>=b[i]&&c[i]>=a[i])||(b[i]>=a[i]&&a[i]>=c[i])){a2[i]=a[i],a3++,minx0[i]=m-a2[i];}
			else if((b[i]>=a[i]&&c[i]>=b[i])||(b[i]>=c[i]&&a[i]>=b[i])){b2[i]=b[i],b3++,minx1[i]=m-b2[i];}
			else if((b[i]>=c[i]&&c[i]>=a[i])||(c[i]>=b[i]&&a[i]>=c[i])){c2[i]=c[i],c3++,minx2[i]=m-c2[i];}
		}
		sort(a2,a2+a3),sort(b2,b2+b3),sort(c2,c2+c3);
		sort(a,a+n),sort(b,b+n),sort(c,c+n);
		m=max(max(a1,b1),c1);
		sort(minx0,minx0+a3),sort(minx1,minx1+a3),sort(minx2,minx2+a3);
		while(a1>n/2){
			if(minx1[bb]>minx2[cc])s-=minx1[bb],bb+=1;
			else s-=minx2[cc],cc+=1;
			a1--;
		}
		while(b1>n/2){
			if(minx0[aa]>minx2[cc])s-=minx0[aa],aa+=1;
			else s-=minx2[cc],cc+=1;
			b1--;
		}
		while(c1>n/2){
			if(minx0[aa]>minx1[bb])s-=minx0[aa],aa+=1;
			else s-=minx1[bb],bb+=1;
			c1--;
		}
		cout<<s<<endl;
	}
	return 0;
}
