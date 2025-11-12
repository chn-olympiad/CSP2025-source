#include<bits/stdc++.h>
using namespace std;
bool abc(int x, int y){
	if(x>=y){
		return x;
	}else{
		return y;
	}
	
	
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	int d,c[1001];
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0' || s[i]<'a'){
			c[i]=s[i]-48;
			d++; 
		}
	}	
	
	for(int i=0; i<d; i++){
		if(c[i]==9){
			cout<<c[i];
			
		}else if(c[i]==8){
			cout<<c[i];
			
		}else if(c[i]==7){
			cout<<c[i];
			
		}else if(c[i]==6){
			cout<<c[i];
			
		}else if(c[i]==5){
			cout<<c[i];
			
		}else if(c[i]==4){
			cout<<c[i];
			
		}else if(c[i]==3){
			cout<<c[i];
			
		}else if(c[i]==2){
			cout<<c[i];
			
		}else if(c[i]==1){
			cout<<c[i];
		
		}else if(c[i]==0){
			cout<<c[i];
		}
	}

	fcolse(stdin);
	fcolse(stdout);
	return 0;

} 
