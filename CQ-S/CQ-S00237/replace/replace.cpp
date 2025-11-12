#include<bits/stdc++.h>
using namespace std;
string th[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int r,p;
	cin>>r>>p;
	for(int i=1;i<=r;i++) cin>>th[i][1]>>th[i][2];
	while(p--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=0;i<a.size();i++){
			string p="";
			for(int j=i;j<a.size();j++){
				p+=a[j];
//				cout<<"i="<<i<<",j="<<j<<",p="<<p<<endl;
				for(int k=1;k<=r;k++){
					if(p==th[k][1]){
//						cout<<"accent of th["<<k<<"]";
						string wz="";
						for(int l=0;l<i;l++) wz=wz+a[l];
						for(int l=i;l<=j;l++) wz=wz+th[k][2][l-i];
						for(int l=j+1;l<a.size();l++) wz=wz+a[l];
//						cout<<",wz="<<wz<<endl;
						if(wz==b){
//							cout<<"ans++! become "<<"th["<<k<<"] :"<<th[k][1]<<" To "<<th[k][2]<<endl;
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
