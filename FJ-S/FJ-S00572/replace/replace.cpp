#include<bits/stdc++.h>
using namespace std;
int n,q;string a[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
cin>>n>>q;
for(int i=0;i<n;i++)cin>>a[i][0]>>a[i][1];
while(q--){
int as=0;
	string x,y;
	cin>>x>>y;
	for(int i=0;i<n;i++){
		if(x==a[i][0]&&y==a[i][1])as++;
		bool f=1;
		if(x[0]==a[i][0][0]){
			for(int k=0;k<x.size();k++){
				if(x[k]!=a[i][0][k]){
					f=0;
					break;
				}
			}
		}
		if(f){
			for(int k=0;k<x.size();k++){
				if(x[k]!=a[i][0][k]){
					f=0;
					break;
				}
			}		
	}
	if(f)as++;

}
	cout<<as<<endl;
}
return 0;
}
