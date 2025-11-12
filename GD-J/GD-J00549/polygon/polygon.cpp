#include<bits/stdc++.h>
using namespace std;
int n,ar[5010],m,z,g,h[5010];
long long s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		h[i]=h[i-1]+ar[i];
		z=z+ar[i];
	}
	sort(ar+1,ar+1+n);
	m=ar[n];
	if(z<=2*m){
		cout<<"0";
		return 0;
	}else if(n==3){
		cout<<"1";
		return 0;
	}else{
		s++;
		if(n==4){
			for(int i=1;i<=n-1;i++){
				if((z-ar[i])>2*m){
					s++;
				}
			}
			if((ar[1]+ar[2])>ar[3]){
				s++;
			}
		}else{
			for(int i=1;i<=n-2;i++){
				for(int j=i+2;j<=n;j++){
					if(h[j]-h[i-1]>2*ar[j]){
						s++;
					}
				}
			}
			s--;
		}
	}
	cout<<s;
	return 0;
} 
