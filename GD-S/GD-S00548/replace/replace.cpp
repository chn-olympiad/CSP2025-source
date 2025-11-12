#include<bits/stdc++.h>
using namespace std;
int n,q;
long long num;
string a[400005],b[400005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<2*n;i++){
		cin>>a[i];
	}for(int i=0;i<2*q;i++){
		cin>>b[i];
	}
	for(int i=0;i<q;i++){
		string m="";
		num=0;
		for(int j=0;j<b[i*2+1].size();j++){
			if(b[i*2+1][j]!=b[i*2][j]){
				m+=b[i*2+1][j];
			}
		}for(int j=0;j<n;j++){
			for(int z=0;j<a[j*2+1].size();j++){
				if(a[j*2+1][z]+a[j*2+1][z+1]==b[i*2][j]){
					num++;
				}
			}
		}cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
