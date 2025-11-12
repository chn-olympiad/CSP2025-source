#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		if(n==200){
			return 0;
		}
		int cm[n+10][4];
		for(int j=0;j<n;j++){
			cin>>cm[j][0];
			cin>>cm[j][1];
			cin>>cm[j][2];}
		int q=0;
		for(int su=0;su<pow(3,n);su++){
			int r=0,a=0,b=0,c=0,in=su;
			bool dure=true;
			for(int k=0;k<n;k++){
				if(in<pow(3,n-k-1)){
					r+=cm[k][0];
					a++;
					if(a>n/2) dure=false;
				}
				else if(in<2*pow(3,n-k-1)){
					r+=cm[k][1];
					in-=pow(3,n-k-1);
					b++;
					if(b>n/2) dure=false;
				}
				else{
					r+=cm[k][2];
					in-=2*pow(3,n-k-1);
					c++;
					if(c>n/2) dure=false;
				}
			}
			if(r>q and dure) q=r; 
		}
		cout<<q<<"\n";
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
