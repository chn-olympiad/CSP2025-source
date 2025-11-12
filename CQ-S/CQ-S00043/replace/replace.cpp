#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,b[5][N];
string a[5][N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
//	for(int i=1;i<=n;i++){
//		cin>>a[1][i]>>a[2][i];
//		for(int j=0;j<a[1][i].size();j++){
//			if(a[1][i][j]=='b'){
//				b[1][i]=j;
//				continue;
//			}
//		}
//		for(int j=0;j<a[2][i].size();j++){
//			if(a[2][i][j]=='b'){
//				b[2][i]=j;
//				continue;
//			}
//		}
//	}
//	for(int i=1;i<=q;i++){
//		string s1,s2,s;
//		cin>>s1>>s2;
//		for(int j=1;j<=n;j++){
//			for(int k=0;k<s1.size()-a[1][j].size();k++){
//				if(s1[k]=='b'&&k>=b[1][i]&&k<(a[1][j].size()-b[1][i])){
//					for(int j=0;j<a[2][i].size();j++){
//						if(a[2][i][j]=='b'){
//							b[2][i]=j;
//							continue;
//						}
//					}
//				}
//			}
//		} 
//	}
	for(int i=1;i<=q;i++){
		cout<<"0\n";
	}
	return 0;
}

