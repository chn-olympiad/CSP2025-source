#include<bits/stdc++.h>
using namespace std;

int a[110],num,hang=1,lie=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			num++;
		}
	}
	int a=num/n,b=num%n;
	hang+=a;
	if(hang%2==0)lie=n-b;
	else lie+=b;
	cout<<hang<<" "<<lie;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
