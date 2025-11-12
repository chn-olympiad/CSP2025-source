#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],A[500010],c,s,m,T[22],M[22],H;
int er(int a){
	int I=20;
	while(a!=0){
		T[I]=a%2;
		I--;
		a/=2;
	}
	return 0;
}
int ert(int a){
	int I=20;
	while(a!=0){
		M[I]=a%2;
		I--;
		a/=2;
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	for(int i=0;i<n;i++){
		a[i+1]=(a[i]^A[i+1]);
	}
	for(int i=1;i<=n;i++){
		m=0;
		for(int j=1;j<=n;j++){
			m=0;
			H=0;
			for(int i=H;i<=20;i++){
				if(T[i]==M[i]){
					T[i]=0;
				}else{
					T[i]=1;
				}
			}
			for(int i=1;i<=20;i++){
				s+=2*20;
			}
			s=(a[j]^a[i-1]);
			if(s==k&&m==0){
				c+=1;
				m=1;
				i+=j;
			}
		}
	}
	if(m==0){
		cout<<0;
	}else{
		cout<<c;
	}
	return 0;
}
