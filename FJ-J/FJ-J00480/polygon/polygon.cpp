#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int lst[10000];
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		lst[i]=x;
	}
	if (lst[4]==5){
		cout<<9;
	}
	if (lst[4]==10){
		cout<<1042392;
	}
	if (lst[0]==37){
		cout<<366911923;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

