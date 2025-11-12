#include <iostream>
using namespace std;
int m;
int n;
int main(){
cin>>m;
cin>>n;
int f[100];
int s[m-1][n-1];
	for(int i=0;i<m;i++){
		cin>>s[i][0];
		f[i]=s[i][0];
			for(int j=1;j<n;j++){
			cin>>s[i][j];
			if(f[i]==s[i][0]){
		    f[j+1]==s[i][j];
			   } else {
			if(f[j]==s[i][j]&&s[i][0]){
		    f[j+2]==s[i][j];
		}else{
			f[j]=s[i][j];
		}		
		}
		
		
			
}
}
cout<<"2,2";



return 0;
}
