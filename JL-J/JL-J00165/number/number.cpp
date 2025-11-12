#include<bits/stdc++.h>
using namespace std;
int num[10],n1;
string n,m;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);    
    cin>>n;
    n1=n.length()-1;
    for(int i=0;i<=n1;i++){
		if(n[i]-'0'>=0 and n[i]-'0'<=9){
		    num[n[i]-'0']++;	
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]>0){
			m+=to_string(i);
			num[i]--;
		}
	}
	cout<<m;
    return 0;
}
