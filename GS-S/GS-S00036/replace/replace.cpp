#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string a[50005][2],b[50005][2];
	int a1,b1;
	cin>>a1>>b1;
	for(int i=0;i<a1;i++){
		cin>>a[i][0]>>a[i][1];
	}for(int i=0;i<b1;i++){
		cin>>b[i][0]>>b[i][1];
	}for(int i=0;i<b1;i++){
		int aab=0;
		if(b[i][0]==b[i][1])cout<<0<<"\n";
		else{
			for(int j=0;j<b[i][0].length();j++){
				if(b[i][0][j]!=b[i][1][j])aab++;
			}
			cout<<aab/2<<"\n";
		}
	}
	return 0;
} 



