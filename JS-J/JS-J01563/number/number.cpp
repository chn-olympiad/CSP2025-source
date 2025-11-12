#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int l[20];
	cin >> a;
	memset(l,0,sizeof(l));
	int k=a.size();
	for(int i=0;i<k;i++){
		if(a[i]>='0'&&a[i]<='9'){
			int x=a[i]+'0'-96;
			l[x]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=l[i];j++){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
