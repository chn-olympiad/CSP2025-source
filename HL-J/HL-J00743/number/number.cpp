#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string w;
	cin>>w;
	int j=0,ans=0;
	for(int i=0;i<w.size();i++){
		if(w[i]>='0'&&w[i]<='9'){
			a[j]=w[i]-'0';
			ans++;
			j++;
		}
	}
	reverse(a,a+ans);
	for(int i=0;i<ans;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
