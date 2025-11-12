#include<bits/stdc++.h>
using namespace std;
int n,jd,a[100],m=0,man=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> jd;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(jd==0){
        cout << 1 << endl;
        return 0;
    }
    if(jd==1){
    	cout << 2 <<endl;
	}
    for(int i=0;i<n-1;i++){
    	m=a[i];
    	for(int j=i+1;j<n;j++){
    		m=m|a[j];
    		cout << m << endl;
    		if(m==jd){
    			if(j-i+1>man){
    				man=j-i+1;
				}
			}
		}
		m=0;
	}
	cout << man <<endl;
    return 0;
}
