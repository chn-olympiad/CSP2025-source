#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int t;
cin>>t;
while(t--){
int n,cnt=0,a[114514],b[114514],c[114514],d=0,e=0,f=0;
cin>>n;
for(int i=1;i<=n;i++){
	 cin>>a[i]>>b[i]>>c[i];
}
sort(a+1,a+1+n);
sort(b+1,b+1+n);
sort(c+1,c+1+n);
for(int i=n;i>=1;i--){
int m;
m=max(a[i],max(b[i],c[i]));
if(m==a[i]&&d<n/2){cnt+=m;d++;}
if(m==b[i]&&e<n/2){cnt+=m;e++;}
if(m==c[i]&&f<n/2){cnt+=m;f++;}
}
cout<<cnt<<endl;
}
return 0;
}

