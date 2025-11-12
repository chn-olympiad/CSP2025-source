#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string a[200100],b[200100],c[200100],d[200100];
bool in(string x,string y){
	for(int i=1;i<=y.length();i++){
		for(int j=1;j<=x.length();j++){
			if((x[j]==y[i] && x[j+1]==y[i+1]) || (x[j]==y[i] && x[j-1]==y[i-1] && j==x.length())){
				return true;
			}
		}
	}
	return false;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>c[i]>>d[i];
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(in(a[i],c[j]) and in(b[i],d[j]) and c[j].length()==d[j].length()){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
} 
