#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[222222],b[222222];
int c[222222];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c[i]=0;
	}
	if(q==1){
		string x,y;
		cin>>x>>y;
		int sum=0;
		if(x.length()==y.length()){
			for(int i=1;i<=q;i++){
			if(a[i].length()>x.length())continue;
				for(int j=0;j<x;j++){
					if(x[j]+k]!=a[i][k]){
						f=1;
						break;
					}
				if(f==0){
				int we=0;
				for(int k=0;k<a[i].length();k++){
					if(y[j+k]!=b[i][k]){
						we=1
						break;
					}
					if(we==0)
					{
						abc=0;
					}else{
						abc=1;
					}
					j+=a[i].length();
				}else if(x[j]!=y[j]){
					abc=1;
					break;
				}
			}
		}
		if(abc==0) 
		    sum++;
	        } 
		}

	    cout<<sum<<endl;
	return 0;
}



