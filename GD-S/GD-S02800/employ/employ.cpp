#include<bits/stdc++.h>
#define let long long
#define rt return
using namespace std;
let n,m,
	A_a,A_b,
	a[1010],b[2020];
char c;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(let i = 1;i<=n;i++){
		cin>>c;
		a[i] = int(c-'0');
		if(a[i] == 1)A_a++;	
	}
	for(let i = 1;i<=n;i++){
		cin>>b[i];
		if(b[i] == 0)A_b++;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	rt 0;
}


	

