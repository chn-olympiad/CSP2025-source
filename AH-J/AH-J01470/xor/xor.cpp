#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010],m,len=0,n,k;
int aw(int a,int b){
	int he=0;
	if (a==b) return 0;
	
	else {
		int j=0;
		while (a!=0||b!=0){
		
			if (a%2==b%2){
				
			}else {
				he+=pow(2,j);
			}
			j++;
			a/=2;b/=2;
		}
		return he;
	}
}
int main(){
freopen ("xor.in","r",stdin);
freopen ("xor.out","w",stdout);
cin>>n>>k;
int ans=0;
for (int i=1;i<=n;i++){
	cin>>a[i];
	if(i==2){
		b[i]=aw(a[i-1],a[i]);
}else if (i>2){
		b[i]=aw(a[i],b[i-1]);
}

}
for (int i=n-2;i>=0;i--){
	for (int j=1;j<=n;j++){
	if (b[j]-b[i-1]==k&&b[j]!=-1){
     ans++;
     b[j]=-1;
}
}
}cout<<ans;
return 0;
}
