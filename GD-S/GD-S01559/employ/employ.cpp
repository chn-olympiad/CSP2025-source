#include <bits/stdc++.h>
using namespace std;
long long k[505];
long long a,b,d[505],f=0,h,j,o=0;
string c;
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	k[0]=1;	
	k[1]=1;
	cin>>a>>b;
	for(int z=2;z<=a;z++){
		k[z]=z*k[z-1];
		k[z]%=998244353;
	}
	cin>>c;
	for(int z=0;z<c.length();z++){
		if(c[z]=='1')o++;
	}
	if(a==b&&o!=a){
		cout<<0;
		return 0;
	}
	if(o<b){
		cout<<0;
		return 0;
	}
	for(int z=1;z<=b;z++){
		cin>>d[z];
	}
	sort(d+1,d+1+a);
	for(int z=b;z<=a;z++){
		h=1,j=0;
		for(int y=1;y<=a;y++){
			j++;
			if(c[z]=='0'){
				h*=k[j];
				j=0;
				h%=998244353;
			}
		}
		f+=h;
	}
	cout<<f%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
