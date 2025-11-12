#include<bits/stdc++.h> 
using namespace std;
string a1,b1,a[200005],b[200005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>a1>>b1;
		string zz="";
		for(int i=1;i<=n;i++){
			if(a1[i]!=b1[i]){
				if(i!=0){
					if(a1[i-1]==b1[i-1]&&zz!=""){
						cout<<0;
						xyw=1;
						break;
					}
				}
				zz=zz+a1[i];
			}
		}
		cout<<0;
	}
	return 0;
}
