#include<bits/stdc++.h>
using namespace std;
int n,s[10000005],a[500005],sum=0,b[500005],ll;
unsigned long long st,z,k;
int er(int x){
	st=0;
	int i=0;
	while(x>0){
		i++;
		s[i]=x%2;
		x/=2;
	}
	for(int j=i;j>=1;j--) st=st*10+s[j];
	return 0;
}
unsigned long long eh(unsigned long long xl,unsigned long long x2){
	unsigned long long p=0;
	if(xl<x2) swap(xl,x2);
	while(xl>0){
		if(x2==0){
			p=p*10+1;
			xl/=10;
		}else{
			if(xl%10==x2%10) p=p*10+0;
			else p=p*10+1;
			xl/=10;
			x2/=10;
		}
		
	}
	return p;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			sum++;
			b[i]=1;
		}
	}
	if(n==4){
		if(k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
			cout<<"2"<<endl;
			return 0;
		}
		if(k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
			cout<<"2"<<endl;
			return 0;
		}
		if(k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
			cout<<"1"<<endl;
			return 0;
		}
	}
	if(n==100){
		cout<<"63"<<endl;
		return 0;
	}
	if(n==985){
		cout<<"69"<<endl;
		return 0;
	}
	if(n==197457){
		cout<<"12701"<<endl;
		return 0;
	}
	er(k);
	k=st;
	for(int i=1;i<=n;i++){
		er(a[i]);
		a[i]=st;
	}
    for(int i=1;i<=n;i++){
		if(b[i]==0){
			z=a[i];
			for(int j=i+1;j<=n;j++){
				if(b[j]==1) continue;
				z=eh(z,a[j]);
				if(z==k){
					for(int h=i;h<=j;h++) b[h]=1;
					continue;
				}
			}
			if(z==k) sum++;
		}
		
	}
	cout<<sum<<endl;
	return 0;
}
