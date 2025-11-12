#include<bits/stdc++.h>
using namespace std;
const long long N=5e6+10;
long long n,m;
long long ga[N],gb[N],vab[N],gx,gy,vxy;
string a,b,x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n >>m;
	for (int i=1;i<=n;i++){
		cin >>a >>b;
		for (int j=0;j<a.size();j++){
			if(a[j]=='b') break;
			ga[i]++;
		}
		for (int j=0;j<b.size();j++){
			if(b[j]=='b') break;
			gb[i]++;
		}
		vab[i]=max(ga[i]-gb[i],gb[i]-ga[i]);
	}
	for (int i=1;i<=m;i++){
		cin >>x >>y;
		for (int j=0;j<x.size();j++){
			if(x[j]=='b') break;
			gx++;
		}
		for (int j=0;j<y.size();j++){
			if(y[j]=='b') break;
			gy++;
		}
		vxy=max(gx-gy,gy-gx);
		for (int i=1;i<=n;i++){
			if(vxy==vab[i]){
				cout <<1;
				return 0;
			}
		}
		cout <<0;
	}
	return 0;
}
