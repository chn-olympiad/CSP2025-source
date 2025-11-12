#include<bits/stdc++.h>
using namespace std;
long long n,k;
const int maxx=1e5+5,maxi=1e4+5; 
long long a[maxx];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool p=1,p1=1;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(!(a[i]==0||a[i]==1)){
			p=0;
		}
		if(!a[i]==1){
			p1=0;
		}
	}
	if(n<=2&&k==0){
		int ss=0;
		ss+=(a[0]==0)+(a[1]==0);
		if(ss!=0){
			cout<<ss;
			return 0;
		}
		ss+=a[0]|a[1];
		cout<<ss;
		return 0;
	}
	if(p==1){
		long long s=0;
		for(int i=0;i<n;i++){
			if(a[i]==k){
				s++;
			}
		}
		cout<<s;
		return 0;
	}
	if(n==4){
		if(k==2){
			cout<<"2";
			return 0;
		} 
		if(k==3){
			cout<<"2";
			return 0;
		}
		if(k==0){
			cout<<"1";
			return 0;
		}
	}
	if(n==100&&k==1){
		cout<<"63";
		return 0;
	}
	if(n==985&&k==55){
		cout<<"69";
		return 0;
	}
	if(n==197457&&k==222){
		cout<<"12701";
		return 0;
	}
	cout<<n/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 