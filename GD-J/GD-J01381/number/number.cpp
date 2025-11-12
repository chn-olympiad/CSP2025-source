#include<bits/stdc++.h> 
using namespace std;
string a;
string m;
char u[58];
int t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>=48&&a[i]<=57){
			int o=a[i];
			u[o]++;
			t++;
		}
	}
	int tt=57;
	for(int i=1;i<=t;i++){
		if(u[tt]>=1){
			char p=tt;
			m=m+p;
			u[tt]-=1;
		}else{
			tt-=1;
			t++;
		}
	}
	cout<<m;
	return 0;
}
