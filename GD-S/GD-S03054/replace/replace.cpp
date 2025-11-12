#include<bits/stdc++.h>
using namespace std;
int n,v;
struct node{
	string a,b;
}q[200001];
bool e(string x,string y){
	if(y.size()>x.size()) return false;
	for(int i=0;i<=x.size()-y.size();i++){
		if(x[i]==y[0]&&x[i+y.size()-1]==y[y.size()-1]){
			bool u=true;
			for(int j=i;j<=i+y.size()-1;j++){
				if(x[j]!=y[j-i]){
					 u=false;
					 break;
				}
			}
			if(u) return true;
			
		}
	}
	return false;
}
bool t(string x,int i,string h){
	int j=i;
	for(i;i<j+h.size()-1;i++){
		//cout<<i<<" "<<i-j<<endl;
		if(x[i]!=h[i-j]) return false;
	}
	return true;
}
bool s(string x,string y,int u){
	if(x.size()!=y.size()) return false;
	string h=q[u].a,h1=q[u].b;
	//cout<<x<<" "<<h<<endl;
	if(e(x,h)&&e(y,h1)){
		
		for(int i=0;i<x.size();i++){
			if(t(x,i,h)){
			//	cout<<"a"<<" ";
				string d=x;
				
				for(int k=i;k<i+h.size();k++){
					d[k]=h1[k-i];
				}
				//cout<<d;
				if(d==y) return true;
				
				
			}else continue;
		}
		
		
		return false;
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>v;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].b;
	}
	for(int i=1;i<=v;i++){
		string t,t1;
		cin>>t>>t1;
	//	cout<<t<<" "<<t1<<endl;
		int sum=0;
		for(int j=1;j<=n;j++){
			if(s(t,t1,j)) sum++;
		}
		cout<<sum<<endl;
	}

	return 0;
}

