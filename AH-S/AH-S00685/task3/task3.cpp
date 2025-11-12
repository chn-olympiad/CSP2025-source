#include<bits/stdc++.h>
using namespace std;
#define gt() getchar()
typedef long long ll;
const int mn=2*1e5+1;
int n,q,x,num;
string a[mn*2],qx;
char o[5000001];
int main(){
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i+=2){
		cin>>a[i]>>a[i+1];
	}
	while(o[x++]=getchar()){
		if(o[x]>'z' or o[x]<'a') break;
		}
	for(int i=1;i<=n;i+=2){
		int tot=0;bool b=0;
		while(a[i][tot]==a[i+1][tot]) tot++;
		for(int i=0;i<x-1;i++){
			if(a[i+1][tot++]!=o[i]){
				b=1;break;}
			if(b) break;
			else{
				num++;}
		}
	}
	cout<<num<<endl;
    return 0;
}
