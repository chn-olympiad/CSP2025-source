#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[n][2],j[q][2];
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<q;i++){
		cin>>j[i][0]>>j[i][1];
	}
	for(int i=0;i<q;i++){
		int shu=0;
		for(int p=0;p<n;p++){
			if(a[p][0]==j[i][0]){
				shu++;
			}
			if(a[p][1]==j[i][1]){
				shu++;
			}
		}
		cout<<shu<<endl;
	}
	return 0;
}
