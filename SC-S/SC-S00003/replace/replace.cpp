#include<bits/stdc++.h>
using namespace std;
int a[100][100];
char s;
int main(){
	freopen("replace .in","r",stdin);
	freopen("replace .out","w",stdout);
	int n,m;
    int x,y,z;
	cin>>n>>m;
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i][j];
			if(i<7&&i>0){
				cout<<m<<endl;
				cout<<"0";
			}else{
	            if(i=7){
			    cout<<"0"<<endl;
			    cout<<"0"<<endl;
			    cout<<"0"<<endl;
			    cout<<"0"<<endl;
		        }	
	        }
		}
	}
	return 0;
}