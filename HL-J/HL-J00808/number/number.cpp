#include<bits/stdc++.h>
using namespace std;
string a;
int mn;
int b[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
    cin>>a;
    b[0]=count(a.begin(),a.end(),'0'); 
    b[1]=count(a.begin(),a.end(),'1');
    b[2]=count(a.begin(),a.end(),'2');
    b[3]=count(a.begin(),a.end(),'3');
    b[4]=count(a.begin(),a.end(),'4');
    b[5]=count(a.begin(),a.end(),'5');
    b[6]=count(a.begin(),a.end(),'6');
    b[7]=count(a.begin(),a.end(),'7');
	b[8]=count(a.begin(),a.end(),'8');
	b[9]=count(a.begin(),a.end(),'9');
	for(int i=9;i>=0;i--){
		for(int j=b[i];j>0;j--){
            cout<<i;
	    }
	}
	fclose(stdin);
	fclose(stdout);
} 
