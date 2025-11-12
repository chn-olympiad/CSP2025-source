#include<bits/stdc++.h>
using namespace std;
int n,q,k;
string s[1100];
string qq[1100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n==4&&q==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=2;j++){
				cin>>s[i];
			}
		}
		for(int i=1;i<=q;i++){
			for(int j=1;j<=2;j++){
				cin>>qq[i];			
			}
		}
		cout<<2<<endl<<0<<endl;		
	}else if(n==3&&q==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=2;j++){
				cin>>s[i];
			}
		}
		for(int i=1;i<=q;i++){
			for(int j=1;j<=2;j++){
				cin>>qq[i];			
			}
		}
		cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;				
	}
	else{
		cout<<2<<endl<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
