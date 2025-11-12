#include <bits/stdc++.h>
using namespace std;
int a[105];
int ans[20][20],cet;
int main(){
	//freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int nm=n*m;
	for(int i=1;i<=nm;i++){
      cin>>a[i];
}
int tag=a[1];
int x=0,y=0;
sort(a+1,a+nm+1,greater<int>());
for(int i=1;i<=nm;i++){
	int x=i/4+1;
	if(x%4==0){
		x-=1;
	}
	if(x%2==1)y++;
	
}

	return 0;
}
