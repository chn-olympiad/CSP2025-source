//520103201112290813 GZ-S00049  Áõ×ÓÒú 
#include<bits/stdc++.h>
using namespace std;
long long n,m,z=0;
vector<long long> c(10000000);
vector<char> s(10000000);
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){cin>>s[i];
	}
	for(long long i=0;i<n;i++){cin>>c[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n;j++){
			if(c[i]>c[j]){
				swap(c[i],c[j]);
			}
		}
	}
	long long pl=0,r=0;
	for(long long k=0;k<n;k++){	
	//cout<<"k "<<k<<" c[k] "<<c[k]<<" pl "<<pl<<" r "<<r<<endl;	
		if(pl>=c[k]){
			pl++;
			continue;
		}else{
			if(s[k]=='0'){
				pl++;
				continue;
			}
			else{
				r++;
			}
		}
	}
	if(r>=m){
		z++;
	}
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n;j++){
			swap(c[i],c[j]);
			for(long long k=0;k<n;k++)
				cout<<c[k]<<' ';
			long long pl=0,r=0;
			for(long long k=0;k<n;k++){
			//cout<<"k "<<k<<" c[k] "<<c[k]<<" pl "<<pl<<" r "<<r<<endl;
				if(pl>=c[k]){
					pl++;
					continue;
				}else{
					if(s[k]=='0'){
						pl++;
						continue;
					}
					else{
						r++;
					}
				}
				
			}
			if(r>=m){
				z++;
			}
		}
	}
	cout<<z%998244353;
	return 0;
}

