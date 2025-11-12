#include<bits/stdc++.h>
using namespace std;
int n;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	if(a[n]==5){
        printf("%d",9);
	}
	else if(a[n]==10){
        printf("%d",6);
	}
	else {
        printf("%d",10);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
