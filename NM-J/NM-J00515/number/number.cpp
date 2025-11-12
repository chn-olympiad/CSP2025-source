#include<bits/stdc++.h>


using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    string b;
    cin>>a;
    int cnt = 0;
    int c = a.size();
    for(int i = 0;i < c;i++){
        if('0'<=a[i] && a[i] <= '9'){
            b += a[i];
            cnt++;
        }
    }
    string ans;
    int m[1000005],f = 0;
    for(int i =0;i < b.size();i++){
    	m[f] = b[i]- '0';
    	f++;
	}
	sort(m,m+f);
	for(int i = b.size()-1;i>=0;i--){
		cout<<m[i];
	}
	
    
   
   return 0;
}