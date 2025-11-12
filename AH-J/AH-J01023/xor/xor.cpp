#include<bits/stdc++.h>
using namespace std;
int s[200005],j;
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int a,k;
	cin>>a>>k;
	for(int d=1;d<=a;d++){
		cin>>s[d];
	}
	for(int d=1;d<a;d++){
		if(s[d]==k){
			j++;
		}
		else if((s[d]^s[d+1])==k){
			j++;
			d++;
		}
	}
	cout<<j;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
