#include<bits/stdc++.h>
using namespace std;
int main(){
	int s;
	int maxn=0,mind=0;
	cin>>s;
	for(int i=1;i<=s;i++){
		if(s>maxn){
			maxn=s;
		}else if(maxn>mind){
			mind=maxn;
		}
	}
	return 0;
}
