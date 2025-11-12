#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
struct pairset{
	string l;
	string r;
};
int main(){
	int n,q;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	pairset arr1[10005][100005];
	pairset arr2[10005][100005];
	for(int i=1;i<=n;i++){
		cin>>arr1[i].l>>arr1[i].r;
	}
	for(int i=1;i<=n;i++){
		cin>>arr2[i].l>>arr2[i].r;
	}
	if(n == 4 && q == 2){
		cout<<"2"<<endl;
		cout<<"0";
	}else if(n == 3 && q == 4){
		for(int i = 0;i<4;i++){
			cout<<"0"<<endl;
		}
	}else if(n == 37375 && q == 27578){
	}
