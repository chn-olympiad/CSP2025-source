#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	 long long n,m,cut;
	 long long test[1000000];
	 long long a=1,b=1;
	 cin>>n>>m;
	 cut=n*m;
	 for(int i=1;i<=cut;i++){
		 cin>>test[i];
		}
		for(int i=2;i<=cut;i++){
			if(test[1]<test[i]){
				b=b+1;
				if(b>m){
					a=a+1;
				}
			}else if(test[1]>test[i+1]){
				a=a;
				b=b;
				}	
		}
				cout<<a<<" "<<b;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}

