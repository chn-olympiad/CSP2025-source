#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,cnt=0,len=0,m=0;
	string f,g;
	bool s=true;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string a;
		string b;
		cin>>a>>b;
		len=a.length();
		f=b;
		g=a;
	}
	for(int i=0;i<q;i++){
		string c,d;
		cin>>c>>d;
		for(int j=0;j<len;j++){
		   for(int k=j;k<len;k++){
              if(g[m]!=c[k]||f[m]!=d[k]){
              	s=false;
			  }
			   m++;
		   }
		   if(s){
	      	 cnt++;
		   }
		    s=true;
	    }
	    cout<<cnt<<endl;
	    cnt=0;
	}
	return 0;
}
