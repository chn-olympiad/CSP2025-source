#include <bits/stdc++.h>
using namespace std;
int j=-1,a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[++j]=n[i]-'0';
		}
	}
	sort(a+0,a+j);
	if(a[j]==0){
		cout<<0;
		j=0;
	}
	for(int i=j-1;i>=0;i--) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

