#include<bits/stdc++.h>
using namespace std;
string n;
long long a[1000010],b,k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	b=n.size();
	for(int i=0;i<b;i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[k]=n[i]-'0';
			k++;
		}
	}
	sort(a,a+k+1);
	for(int i=k;i>0;i--){
		cout<<a[i];
	}
	return 0;
}