#include<bits/stdc++.h>
using namespace std;
string s;
int n=0;
vector <int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for ( int i=0;i<s.length();i++){
		int v=s[i];
		v-=48;
		if (0<=v&&v<=9){
			a.push_back(v);
			n++;
		}
	}
	if (n!=0){
	for (int j=0;j<n;j++){
		int b=a[j],c=j;
		for (int i=j;i<n;i++){
			if (b<a[i]){
			b=a[i];
			c=i;
		}
		swap(a[j],a[c]);
		}
	}
	for (int i=0;i<n;i++){
		cout<<a[i];
	}
}
	return 0;
}






