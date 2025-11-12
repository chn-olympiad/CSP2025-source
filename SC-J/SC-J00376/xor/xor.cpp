#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int s[N];
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,sum=0;
	cin>>a>>b; 
	
		for(int i=1;i<=a;i++){
			cin>>s[i];
			if(s[i]==b) sum++;
		}
		for(int i=1;i<=a;i++){
			if(s[i]==b) continue;
			else{
				if(s[i]==b+s[i+1]){
					sum++;
					s[i+1]=b;
				}
			}
		}
		cout<<sum;
	
	return 0;
}