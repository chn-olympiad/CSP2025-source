#include<bits/stdc++.h>
using namespace std;
bool shuzi(char c){
    if(c>='0'&&c<='9') return 1;
    else return 0;
}
int cti(char c){
	if(c=='0') return 0;
	if(c=='1') return 1;
	if(c=='2') return 2;
	if(c=='3') return 3;
	if(c=='4') return 4;
	if(c=='5') return 5;
	if(c=='6') return 6;
	if(c=='7') return 7;
	if(c=='8') return 8;
	if(c=='9') return 9;
}
int l[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
    string a;
    getline(cin,a);
    if(a.size()==1&&shuzi(a[0])==1){
        cout<<a;
        return 0;
    }
    
    int chang=a.size();
    for(int i=0;i<chang;i++){
	    if(shuzi(a[i])==1){
			l[cti(a[i])]++;
			
		}
	}
	
	for(int i=9;i>=0;i--){
		if(l[i]!=0){
	        for(int j=0;j<l[i];j++){	
				cout<<i;
			} 	
		}
	
	}
    return 0;
}
