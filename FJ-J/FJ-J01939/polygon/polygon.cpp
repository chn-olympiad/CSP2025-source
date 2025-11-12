#include <bits/stdc++.h>
using namespace std;
int n,a[5005],m,s,ss;
long long int sum;
int jishu(int k){
	s+=a[k];
	if(k==n){
		return ss;
	}
	if(s>k*2){
		ss++;
	}else{
		for(int i =k+1;i<=n;i++){
			jishu(a[i]);}
			
		
	}
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		m = max(a[i],m);
	}sort(a+1,a+n+1);
	if(m==1){
		for(int i =3;i<=n;i++){
			sum+=n/i;
		}cout<<sum;
		return 0;
	}else if(n<=3){
		if(a[3]<a[1]+a[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	else{
		for(int i =1;i<=m;i++){
			s = 0;ss = 0;
		sum += jishu(i);}
		cout<<sum;
	}return 0;
}