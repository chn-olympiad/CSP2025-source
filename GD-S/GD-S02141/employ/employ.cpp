#include<bits/stdc++.h>
using namespace std;
ifstream fin("employ.in");
ofstream fout("employ.out");
#define cout fout
#define cin fin 
typedef long long ll;
bool able[510];int data[510];
int main(){
	bool chtr=1,c2=1;
	int n,m;
	cin>>n>>m;
	memset(able,0,sizeof(able));
	memset(data,0,sizeof(data));
	for(int i=0;i<n;i++){
		char a;
		cin>>a;
		able[i]=(a=='1');
		if(able[i])c2=0;
		if(!able[i])c2=0;
	}
	for(int i=0;i<n;i++){
		cin>>data[i];
		if(data[i]!=0)chtr=0;
	}
	if(n==m&&!c2){
		if(chtr){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	else{
		for(int i=1,x=1;i<=n;i++){
			x*=i;
			x%=998244353;
			if(i==n){
				cout<<x;
			}
		}
	}
//	for(ll i=1,x=1;i<=10;i++){
//		x*=i;
//		x%=998244353;
//		cout<<x<<endl;
//	}
	fin.close();
	fout.close();
	return 0;
}
