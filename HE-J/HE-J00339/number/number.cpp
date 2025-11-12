#include<bits/stdc++.h>
using namespace std;
string a;
int s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]-'a'>0) s++;
	} 
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			if(a[j]<a[j+1])
			swap(a[j],a[j+1]);
		}
	}
	
	for(int i=s;i<l;i++){
		cout<<a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
