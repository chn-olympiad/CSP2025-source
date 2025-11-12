#include<bits/stdc++.h>
using namespace std;
void as(string b){
	int c=0, s=b.size();
	for(int i=0;i<s;i++){
		if(int(b[i])>=49 && int(b[i])<58){
			continue;
			c++;
		}else{
			b[i]=0;
			
		}
		for(int i=0;i<c;i++){
			cout<<int(b[i]);
			cout<<endl;
		}
	}
	cout<<endl<<c;
}
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdin);
	
	string asdsd=" ";
	
	cin>>asdsd;
	as(asdsd);
	
	
	
	
	return 0;
}
