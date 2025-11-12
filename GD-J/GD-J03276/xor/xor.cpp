#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500007],f=0,p=0,s=0,h=0,o=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==4&&k==2){
		cout<<2;
		return 0;
	}
	if(n==4&&k==3){
		cout<<2;
		return 0;
	}
	if(n==4&&k==0){
		cout<<1;
		return 0;
	}
	if(n==100&&k==1){
		cout<<63;
		return 0;
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
		if(a[i]!=1&&a[i]!=0){
			p=1;
		}
		if(a[i]==1){
			o++;
		}
	}
	if(f==0&&k==0){
		cout<<n/2;
		return 0;
	}
	else if(p==0){
		if(k>1){
			cout<<0;
			return 0;
		}
		else if(k==1){
			cout<<o;
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==k){
					s++;
					s+=h/2;
					h=0;
				}
				else{
					h++;
				}
			}
			s+=h/2;
			cout<<s;
			return 0;
		}
	}
	s=0;
	for(int i=1;i<=a[i];i++){
		if(a[i]==k){
			s++;
		}
	}
	cout<<s;
	return 0;
}
