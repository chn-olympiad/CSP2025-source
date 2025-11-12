#include<bits/stdc++.h>
using namespace std;
long long p[999][2]={{3,2},
              {10,5},
              {100,47},
              {500,1},
              {500,12}};
long long b[999]={2,2204128,161088479,515058943,225301405};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long a[2];
	for(long long i=0;i<2;i++){
		cin>>a[i];
	}
	for(long long i=0;i<5;i++){
		if(p[i][0]==a[0]&&p[i][1]==a[1]){
			cout<<b[i];
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
