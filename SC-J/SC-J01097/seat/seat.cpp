#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat","w",stdin);
	freopen("seat","r",stdout);
	long long a,b,c[1005];
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
			cin>>c[i];		
	}	
	int t=c[1];
	sort(c+1,c+1+a*b);
	for(int i=1;i<=a*b;i++){
		if(c[i]==t){
			if(i>a){
				cout<<i-a<<" "<<b;
			}if(i<a){
				cout<<1<<" "<<b;
			}if(i==a){
				cout<<a<<" "<<i/b;
			}
		}
	}
	return 0; 
	fclose("seat",stdin);
	fclose("seat",stdout);
}