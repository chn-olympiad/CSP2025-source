#include<bits/stdc++.h>
using namespace std;
string a;
char b[1000002];
int i,j=1;
int main(){
    cin>>a;
	int n=a.length();
	for(i=0;i<n;i++){
		if(a[i]<97){
			b[j]=a[i];
			j++;
		}
	}
	sort(b+1,b+1+j);
	for(int k=j;k>=1;k--)cout<<b[k];
	return 0;
}