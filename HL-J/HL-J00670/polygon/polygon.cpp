#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	int q = 0;
	int l[5100];
	for(int i=0;i<a;i++)
	    cin>>l[i];
	for(int i=0;i<a;i++){
		for(int j=i+1;j<a;j++){
			for(int k=j+1;j<a;j++){
				if(l[i]+l[j]+l[k]>2*l[k]){
				    q++;
				}
			}
		}
	}
	cout<<q;
	return 0;
}