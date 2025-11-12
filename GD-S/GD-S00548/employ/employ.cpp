#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string a;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=0;i<n;i++){
		int nt;
		cin>>nt;
		c[nt]++;
	}for(int i=0;i<n;i++){
		if(a[i]==0){
			cout<<"0";
			return 0;
		}
	}for(int j=1;j<n;j++){
			c[j-1]=c[j];
			if(c[0]>j){
				cout<<"0";
				return 0;
			}
		}cout<<"1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
