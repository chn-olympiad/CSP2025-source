#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n,k;
	cin>>n>>k;
	
	vector<vector<int> > subs(n);
	vector<bool> alld(n);
	vector<int> di(n);
	for(int i=0;i<n;i++){
		cin>>di[i];
	}
	subs[0]=di;
	for(int i=1;i<n;i++){
		vector<int> xsu(n-i);
		for(int j=0;j<n-i;j++){
			xsu[j]=subs[i-1][j]^subs[i-1][j+1];
		}
		subs[i]=xsu;
	}
	int res=0;
	for(int i=0;i<n;i++){
		if(!alld[i]){
			int l,r;
			for(int j=0;j<n-i;j++){
				if(subs[j][i]==k){
					res++;
					l=i;
					r=i+j;
					break;
				}
			}
			for(int j=l;j<=r;j++){
				alld[j]=true;
			}
		}
	}
	cout<<res; 
	return 0;
}

