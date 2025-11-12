#include<bits/stdc++.h>
using namespace std;
const int Max=5e3+5;
struct dp{
	int l;
	int r;
};
void solove(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
int l[Max][Max];
vector<dp>	d;
vector<dp> hb[Max];
int main(){
	solove();
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>l[0][i];
		if(l[0][i]==k){
			d.push_back({i,i});
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			l[i][j]=l[i-1][j]^l[0][j+i];
			//cout<<l[i][j]<<" ";
			if(l[i][j]==k){
				d.push_back({j,i+j});
			}
		}
		//cout<<endl;
	}
	for(int i=0;i<d.size();i++){
		hb[0].push_back(d[i]);
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<hb[i-1].size();j++){
			for(int k=j+1;k<hb[i-1].size();k++){
				if(hb[i-1][k].r>=hb[i-1][j].l||hb[i-1][k].l<=hb[i-1][j].r){
					continue;
				}
				hb[i].push_back({min(hb[i-1][j].l,hb[i-1][k].l),max(hb[i-1][k].r,hb[i-1][j].r)});
			}
		}
	}
	int op=0;
	while(hb[op].size()){
		op++;
//		for(int i=0;i<hb[op].size();i++){
//			cout<<hb[op][i].l<<","<<hb[op][i].r<<" ";
//		}
//		cout<<endl;
	}
	cout<<op-1;
	return 0;
}
/*
set?
a b c d
ab bc cd
abc bcd
abcd

if:a d bc abc






*/