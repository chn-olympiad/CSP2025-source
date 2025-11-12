#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,js;
    std::cin>>s;
    long long asd=0;
	for(int i=0;i<s.size();i++) {
		if(s[i]>='0'&&s[i]<='9'){
			js[asd]=s[i];
			++asd;
		}
	}
	for(int j=0;j<asd-1;j++) {
		for(int i=0;i<asd-1;i++) {
		    if(js[i]<js[i+1]) std::swap(js[i],js[i+1]);
	    }
	}
	for(int i=0;i<asd;i++) std::cout<<js[i];
		
	return 0;
}
