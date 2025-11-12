#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r");
	freopen("number.out","w");
    long long a,b,big=-1;
    string c[100000]={};
    string d;
    cin>>d;
    for(int i=0;i<d.size();i++){
        if(d[i]-'0'<0||d[i]-'0'>9){
            continue;
            }else{
                if(d[i]-'0'>big){
                    c[0]=d[i];
            }
        }
    }
	for(int i=0;i<d.size();i++){
		cout<<c[i];
	}
	cout<<d[0]-'0';
	return 0;
}
///
