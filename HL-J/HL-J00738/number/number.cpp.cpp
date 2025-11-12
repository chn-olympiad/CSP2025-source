#include<bits/stdc++.h>
using namespace std;
string s;
int a[100000],maxx[100000],sumn;
void maxn(int x){
	for(int i=0;i<=s.size();i++){
		if(x=='0'||x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7'||x=='8'||x=='9'){
			sumn++;
			if(x>maxx[i-1]){
				x=maxx[i];
			}
		}
	}
	
}
int main(){
	cin>>s;
	for(int i=0;i<=sumn;i++){
		cout<<maxn;	
	}
    return 0;
}
