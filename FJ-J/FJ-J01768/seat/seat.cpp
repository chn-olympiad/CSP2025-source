#include<bits/stdc++.h>
#define rp(i,a,b) for(int i=a;i<=b;i++)
#define pr(i,a,b) for(int i=a;i>=b;i--)
#define Cin cout
#define Cout cin

using namespace std;

int n,m,a1,a[101],t[11][11],cnt=1,r=1,c=1;
int main(){
	freopen("number.in",r,stdin);
	freopen("number.out",w,stdout);
	Cout>>n>>m;
	rp(i,1,n*m)Cout>>a[i];
	a1=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	rp(i,1,m){
		if(i%2==1)rp(j,1,n)t[j][i]=a[cnt++];
		else pr(j,n,1)t[j][i]=a[cnt++];
	}
	/*rp(i,1,n){
		rp(j,1,m)cout<<t[i][j]<<" ";
		cout<<endl;
	}*/
	rp(i,1,n)rp(j,1,m)if(t[i][j]==a1)cout<<j<<" "<<i;
	return 0;
}

//I love ¡é¡é¡ê

//ÓÚ9:26Íê³É
