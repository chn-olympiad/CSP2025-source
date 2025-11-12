#include<bits/stdc++.h>
using namespace std;
long long int t,n;
const int N=2e4+3;
int a,b,c;
int d[N][3]={ a,b,c };
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int n,t;
	cin>>t;
	int cnt=0;
	for(int i=1;i<=t;++i){
		cin>>n;
		cin>>a>>b>>c;
		int n;
    	for(int i=1;i<=n;i++){
        	for(int j=1;j<=i;j++){
        		if(max(a,b,c)){
        		    cnt+=max(a,b,c);
        		}
        	}
    	}
	}
	cout<<cnt<<endl;
	return 0;
}
