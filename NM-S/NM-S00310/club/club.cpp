#include <bits/stdc++.h>
using namespace std;
bool a2[100010],b2[100010],c2[100010];
int a[100010],b[100010],c[100010],t1[100010];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int m,n,i,s=0,j=0,a1=0,b1=0,c1=0;
cin>>m;
while(m--){
cin>>n;
s=n/2;
for(i=1;i<=n;i++){
	cin>>a[i];
	cin>>b[i];
	cin>>c[i];
	if(a[i]>b[i]&&a[i]>c[i]){
		a1++;
		a2[i]=1;
	}else if(b[i]>c[i]&&b[i]>a[i]){
		b1++;
		b2[i]=1;
	}else{
		c1++;
		c2[i]=1;
	}
}
for(i=1;i<=n;i++){
	if(a1<=s&&a2[i]==1){
		j+=a[i];
	}if(b1<=s&&b2[i]==1){
		j+=b[i];
	}if(c1<=s&&c2[i]==1){
		j+=c[i];
	}
	}
cout<<j<<endl;
}return 0;
}
