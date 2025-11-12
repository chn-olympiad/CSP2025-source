#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    int b[114514][3];
    int a[t+1];int s=0;
    for(long long i=1;i<=t;i++){
    	cin>>a[i];
    	for(int j=1;j<=a[i];j++){
    		
    		cin>>b[j][1]>>b[j][2]>>b[j][3];
		}
	}
	for(long long i=1;i<=t;i++){
    	for(int j=1;j<=a[i];j++){
    		sort(b[j][1],b[j][2],b[j][3]);
    		
			s=s+b[j][1];
		}
		cout<<s;
		s=0;
	}
	return 0;
} 
