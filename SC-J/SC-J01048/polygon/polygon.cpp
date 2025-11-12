#include<bits/stdc++.h>
using namespace std;
int k,n,a[5005],cnt,a2[5005],o,mx;
int pd(int f,int l){
	f+=a[o];
	for(int i=l;i<o;i++){
		if(f+a[o-i]>a2[mx-l]){
			cnt++;
		}else{
			o--;
			l++;
			if(i==o-1){
				f=0;
			}
			pd(f,l);
			l--;
			o++;	
		}
		
	}
	
	
	
	return 0;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
o=n;
for(int i=1;i<=n;i++){
	cin>>a[i];
	a2[i]=a[i]*2;
}
mx=o;
sort(a+1,a+1+n);
sort(a2+1,a2+1+n);
pd(0,1);
cout<<cnt%998244353;
return 0;
}