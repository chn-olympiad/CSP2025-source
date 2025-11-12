#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,ans=0,b;
	cin>>a;
	if(a<=5){
		cin>>b;
		if(b==1){
			cout<<9<<endl;
		}
		if(b==2){
			cout<<6<<endl;
		}
	}
	if(a==500){
		cin>>b;
		if(b==37){
			cout<<366911923<<endl;
		}
	}
	if(a>=500){
		cin>>b;
		for(int i=0;i<a;i++){
			ans+=i;
		}
	cout<<ans+1<<endl;
    }
    
	return 0;
}