#include<bits/stdc++.h>
using namespace std;
int wc[1000005];
bool nm(int e,int e2){
	return e>e2;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int s=0;
	int r=0;
	for(int i=0;i<a.size();i++) {
		if(a[i]>=48&&a[i]<=57){
			wc[r]=a[i]-48;
			s++;
			r++;
	    }
	}
	sort(wc,wc+s,nm);
	for(int i=0;i<s;i++){
		cout<<wc[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
