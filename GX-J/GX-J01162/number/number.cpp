#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
     return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    vector<char> s;
    vector<char> k;
    char a=0;
    while(cin>>a){
	    s.push_back(a);
	    
        if(a>='0'&&a<='9'){
			
	        k.push_back(a);
	    }
	}
	sort(k.begin(),k.end(),f);
    for(auto i:k){
		cout<<i;
	}
    return 0;
}
